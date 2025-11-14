# Day18_inventoryManagment
*Student Name:* p.nanada 
*Roll No:* AP25110090190
*Challenge:* Day 14 - inventory management

## Description

It allows a shopkeeper to add product details like ID, name, quantity,
and price for up to 10 items. The user can view all products, check a
summary showing the total inventory value and the most and least valuable 
items, or search for a product by its ID. The menu-driven design makes 
it easy to perform these tasks repeatedly until the user chooses to exit

## Build Commands
### Linux/macOS:
```bash
mkdir -p build
gcc -std=c11 -Wall -Wextra -O2 main.c -o build/program
=========================
   SHOP INVENTORY MENU
=========================
1. Add Product Details
2. View All Products
3. Inventory Summary
4. Search Product by ID
5. Exit
Enter your choice: 1

Enter Product ID: 10
Enter Product Name: apple
Enter Quantity in Stock: 1
Enter Price per Item: 10
Product saved successfully!

=========================
   SHOP INVENTORY MENU
=========================
1. Add Product Details
2. View All Products
3. Inventory Summary
4. Search Product by ID
5. Exit
Enter your choice: 2

======= ALL PRODUCTS =======

Product 1
ID       : 10
Name     : apple
Quantity : 1
Price    : 10.00

=========================
   SHOP INVENTORY MENU
=========================
1. Add Product Details
2. View All Products
3. Inventory Summary
4. Search Product by ID
5. Exit
Enter your choice: 3
