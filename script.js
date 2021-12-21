/*jshint esversion: 6 */
const pictures = [
  "./images/image-product-1.jpg",

  "./images/image-product-2.jpg",

  "./images/image-product-3.jpg",

  "./images/image-product-4.jpg",
];

const number = document.querySelector(".counter-text");
const minus = document.querySelector(".minus");
const add = document.querySelector(".plus");
const btn = document.querySelector(".btn");
const items = document.querySelector(".items");
const checkOut = document.querySelector(".btn-2");
const profile = document.querySelector(".profile");
const cart = document.querySelector(".add-cart");
const cartIcon = document.querySelector("#cart");
const imageItems = [...document.querySelectorAll(".image")];
const displayImage = document.querySelector(".display-image");
const totalAmount = document.querySelector(".total");
const list = document.querySelector(".list");
const navToggle = document.querySelector(".nav-toggle");
const closeBtn = document.querySelector(".close-btn");
let count = 0;

const nextBtn = document.querySelector(".nextPic");
const prevBtn = document.querySelector(".prePic");
let counter = 0;

function changeImg() {
  const image = pictures[counter];
  displayImage.src = image;
}
nextBtn.addEventListener("click", function () {
  counter++;
  if (counter > pictures.length - 1) {
    counter = 0;
  }

  changeImg();
});
prevBtn.addEventListener("click", function () {
  counter--;
  if (counter < 0) {
    counter = pictures.length - 1;
  }
});

navToggle.addEventListener("click", () => {
  list.classList.add("show-list");
});
closeBtn.addEventListener("click", () => {
  list.classList.remove("show-list");
});

add.addEventListener("click", function () {
  let countAdd = count++;
  number.innerHTML = countAdd;
});
minus.addEventListener("click", function () {
  if (count > 0) {
    number.innerHTML = count--;
  }
});

cartIcon.addEventListener("click", () => {
  cart.classList.toggle("add-cart-show");
});

btn.addEventListener("click", () => {
  const oneItem = document.createElement("div");
  oneItem.classList.add("oneItem");
  items.appendChild(oneItem);
  oneItem.innerHTML += `<div class="item-image">
 <img src="${displayImage.src}" alt="" />
</div>
<div class="items-infos">
 <p>Fall limited edition sneakers</p>
 <p>$125.00 x ${number.innerHTML}<strong> $${
    125.0 * number.innerHTML
  }</strong></p>
</div>
<button class="delete" onclick="deleteCart()">
 <i class="fa fa-trash" aria-hidden="true"></i>
</button>`;

  checkOut.style.visibility = "visible";
});

function deleteCart() {
  const removeCart = document.querySelector(".delete");
  const element = removeCart.parentElement;
  items.removeChild(element);
  console.log(element);
}

imageItems.map((element) => {
  element.addEventListener("click", (e) => {
    let certainImage = e.target.src;
    displayImage.src = certainImage;
  });
});
