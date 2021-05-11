#pragma once

typedef struct Product_Type1 {
	char name[30];
	char type[30];
	char soket[10];
	float price;
	int quantity;
	int id;
}PRODUCT_TYPE1;

typedef struct Product_Type2 {
	char name[30];
	char type[30];
	int  VRAM;//Ram 
	float price;
	int quantity;
	int id;
}PRODUCT_TYPE2;

typedef struct Product_Type3 {
	char name[30];
	char type[30];
	float price;
	int quantity;
	int id;
}PRODUCT_TYPE3;

//manus for program
void CreatingFiles();
void manu();
void EnterManu();
void DeleteMenu();
void ShowMenu();
void SellMenu();

//enter the product in wealhouse 
void EnterTheProductType1(char[30]);//entering the name of the file for whic type you wont the product procesor or 
void EnterTheProductType2(char[30]);
void EnterTheProductType3(char[30]);

//geting products 
PRODUCT_TYPE1* GetingProductType1(PRODUCT_TYPE1*, int*,char*);