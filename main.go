package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"strings"

	"golang.org/x/net/html"
)

var base_url string = "https://sflix.to/"

func RemoveDuplicates(s []string) []string {
	bucket := make(map[string]bool)
	var result []string
	for _, str := range s {
		if _, ok := bucket[str]; !ok {
			bucket[str] = true
			result = append(result, str)
		}
	}
	return result
}

func Request(url string) (data string) {
	client := http.Client{}

	request, err := http.NewRequest(http.MethodGet, url, nil)
	if err != nil {
		log.Fatalln(err)

	}

	response, err := client.Do(request)

	body, err := ioutil.ReadAll(response.Body)

	return string(body)

}
func GetLinks(body string) (data []string) {
	var links []string
	var islink bool = false
	token := html.NewTokenizer(strings.NewReader(body))

	for {
		next_token := token.Next()
		switch {
		case next_token == html.ErrorToken:
			return links
		case next_token == html.StartTagToken, next_token == html.EndTagToken:
			t := token.Token()
			islink = t.Data == "a"
			if islink {
				for _, attr := range t.Attr {
					if attr.Key == "href" {
						links = append(links, attr.Val)
					}
				}
			}
		}
	}

}
func main() {

	var val []string
	movie := flag.String("m", "john-wick", "p")
	flag.Parse()

	body := Request(base_url + "search/" + *movie)
	data := GetLinks(body)

	data = RemoveDuplicates(data)
	for _, v := range data {
		if strings.Contains(v, *movie) && strings.HasPrefix(v, "/movie/") {
			trimmed := strings.TrimLeft(v, "/movie/")
			fmt.Println(trimmed)

			val = append(val, "/watch-movie/"+trimmed)
		}
	}

	n := Request(base_url + val[0])
	fmt.Println(n)
}
