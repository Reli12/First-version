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

//creating all bin files whic is needed for program.
void CreatingFiles();

//manus for program
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
PRODUCT_TYPE1* GetingProductType1(PRODUCT_TYPE1*, int*,char*);//Pointer of product, pointer on number of product, pointer for name of file.
PRODUCT_TYPE2* GetingProductType2(PRODUCT_TYPE2*, int*, char*);
PRODUCT_TYPE3* GetingProductType3(PRODUCT_TYPE3*, int*, char*);

//printing products 
void PrintAllProductsProcesorsAndMatherboard(PRODUCT_TYPE1* ,char*,int);//pointer for name of file that is need to open. 
void PrintAllProductsGraphichCardAndRAM(PRODUCT_TYPE2* , char* , int );
void PrintAllProductsCaseAndColer(PRODUCT_TYPE3* , char* , int );

//BubleSort
PRODUCT_TYPE1* BubleSortProcesorsAndMatherboard(PRODUCT_TYPE1* , int*);
PRODUCT_TYPE2* BubleSortedGraphichCardAndRAM(PRODUCT_TYPE2*, int*);
PRODUCT_TYPE3* BubleSorteCaseAndColer(PRODUCT_TYPE3*, int*);

//Selling items 
int SellProcesorsAndMatherboard(char*, int , char*,int* );
int SellGraphichCardAndRAM(char* , int , char* , int* );
int SellCaseAndColer(char*, int, char*, int*);

//Deliting items functions 
int DeliteProcesors(char* , int , char* , int* );
int DeliteMatherboard(char* , int , char* , int* );
int DeliteRAMORGraphicCard(char*, int, char*, int*);
int DeliteChaseOrColer(char* , int , char* , int* );