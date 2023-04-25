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

func GetLinks(body string, value string) (data []string) {
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

	movie := flag.String("m", "john-wick", "p")
	flag.Parse()
	client := http.Client{}
	var url string = "https://sflix.to/"

	request, err := http.NewRequest(http.MethodGet, url+"search/"+*movie, nil)
	if err != nil {
		log.Fatalln(err)

	}

	response, err := client.Do(request)

	body, err := ioutil.ReadAll(response.Body)

	data := GetLinks(string(body), *movie)

	for _, v := range data {
        a:=strings.Contains(v,*movie)
        if a {
        }
	}

}
