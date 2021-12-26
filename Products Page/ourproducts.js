/*jshint esversion: 8 */
/* jshint expr: true */

const cart = document.querySelector(".add-cart");
const cartIcon = document.querySelector("#cart");
const list = document.querySelector(".list");
const navToggle = document.querySelector(".nav-toggle");
const closeBtn = document.querySelector(".close-btn");
const productSection = document.querySelector(".products-section");
const main = document.querySelector(".main");
const items = document.querySelector(".items");
const menShoes = document.querySelector("#men-shoes");
const womenShoes = document.querySelector("#women-shoes");
const kidsShoes = document.querySelector("#kids-shoes");
const nameProduct = document.querySelector(".name");

navToggle.addEventListener("click", () => {
  list.classList.add("show-list");
});
closeBtn.addEventListener("click", () => {
  list.classList.remove("show-list");
});
cartIcon.addEventListener("click", () => {
  cart.classList.toggle("add-cart-show");
});

// ****************************** For Men Shoes *********************************************

const getMenProducts = async () => {
  const url = fetch(`https://v1-sneakers.p.rapidapi.com/v1/sneakers?limit=40`, {
    method: "GET",
    headers: {
      "x-rapidapi-host": "v1-sneakers.p.rapidapi.com",
      "x-rapidapi-key": "6d47b7972emsha5bcdb005cde6b7p1c9062jsnee0862a69811",
    },
  });
  try {
    const resp = await url;
    const data = await resp.json();
    const dataresults = data.results;
    const products = dataresults.map((items) => {
      const title = items.title;
      const image = items.media.imageUrl;
      const price = items.retailPrice;
      const brand = items.brand;
      const gender = items.gender;
      let results = "";
      results += `<article class="one-product">
         <div class="img-container">
           <img src="${image}" alt="" class ="shoe-image"/>
         </div>
         <h1>${title}</h1>
         <h2>${brand}</h2>
         <h5>${gender}</h5>
         <h3>$${price}</h3>
         <button class="view-btn">View Item</button>
       </article>`;
      productSection.innerHTML += results;
    });
    const viewBtns = [...document.querySelectorAll(".view-btn")];
    const viewProducts = () => {
      viewBtns.forEach((button) => {
        button.addEventListener("click", (btn) => {
          const singleProductImage =
            btn.target.parentElement.firstElementChild.firstElementChild.src;
          const singleProductTitle =
            btn.target.parentElement.firstElementChild.nextElementSibling
              .innerHTML;
          const singleProductPrice =
            btn.target.parentElement.firstElementChild.nextElementSibling
              .nextElementSibling.nextElementSibling.nextElementSibling
              .innerHTML;
          main.style.display = "flex";
          productSection.style.display = "none";
          document.querySelector(".btn-2").style.visibility = "visible";
          document.querySelector(".name").style.display = "none";
          main.innerHTML = `
      <article class="image-section">
        <button class="back-to-shop"><a href="/Products Page/ourproucts.html"><i class="fas fa-arrow-left"></i></a></button>
        <div class="big-image">
          <img
            src="${singleProductImage}"
            alt=""
          />
        </div>
      </article>
      <article class="text-section">
        <h5>sneaker company</h5>
        <h1>${singleProductTitle}</h1>
        <p class= "desc">
        Lorem ipsum dolor sit amet consectetur adipisicing elit. Praesentium eum
        id veritatis natus, qui fuga voluptate distinctio placeat sed debitis
        voluptas assumenda sunt, amet vero? Eaque deserunt pariatur iste maxime?
      </p>
  
        <div class="prices">
          <h2>${singleProductPrice}</h2>
        </div>
        <div class="add-to-cart">
          <div class="counter">
            <button class="minus"><i class="fas fa-minus"></i></button>
            <span>
              <p class="counter-text">0</p>
            </span>
            <button class="plus"><i class="fas fa-plus"></i></button>
          </div>
          <button class="btn-cart">
            <i class="fas fa-shopping-cart"></i> Add to Cart
          </button>
        </div>
      </article>
    `;
          const btnAdd = document.querySelector(".btn-cart");
          btnAdd.addEventListener("click", () => {
            const oneItem = document.createElement("div");
            oneItem.classList.add("oneItem");
            items.appendChild(oneItem);
            oneItem.innerHTML += `<div class="item-image">
     <img src="${singleProductImage}" alt="" />
    </div>
    <div class="items-infos">
     <p>${singleProductTitle}</p>
     <p>${singleProductPrice} x ${number.innerHTML}<strong> ${
              singleProductPrice * number.innerHTML
            }</strong></p>
    </div>
    <button class="delete" onclick="deleteCart()">
     <i class="fa fa-trash" aria-hidden="true"></i>
    </button>`;
          });

          const number = document.querySelector(".counter-text");
          const minus = document.querySelector(".minus");
          const add = document.querySelector(".plus");
          let count = 0;

          add.addEventListener("click", function () {
            let countAdd = count++;
            number.innerHTML = countAdd;
          });
          minus.addEventListener("click", function () {
            if (count > 0) {
              number.innerHTML = count--;
            }
          });
        });
      });
    };
    viewProducts();

    return products;
  } catch (error) {
    alert(
      "You have exceeded the DAILY quota for Requests on your current plan, BASIC. Upgrade your plan at https://rapidapi.com/tg4-solutions-tg4-solutions-default/api/v1-sneakers"
    );
  }
};

function deleteCart() {
  const removeCart = document.querySelector(".delete");
  const element = removeCart.parentElement;
  items.removeChild(element);
}

window.addEventListener("DOMContentLoaded", getMenProducts);
