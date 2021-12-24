/*jshint esversion: 8 */
/* jshint expr: true */

const list = document.querySelector(".list");
const navToggle = document.querySelector(".nav-toggle");
const closeBtn = document.querySelector(".close-btn");
const cart = document.querySelector(".add-cart");
const cartIcon = document.querySelector("#cart");

cartIcon.addEventListener("click", () => {
  cart.classList.toggle("add-cart-show");
});

navToggle.addEventListener("click", () => {
  list.classList.add("show-list");
});
closeBtn.addEventListener("click", () => {
  list.classList.remove("show-list");
});
