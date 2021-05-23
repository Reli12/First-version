#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
/*
	To do list:
		otvaranje i zatvaranje datoteke funkcije

		ubacivanje proizvoda u datoteku 

		citanje i ispis po nekom kriteriju proizvoda

		Proizvodi:
			maticna ploca:
				-naziv
				-model
				-soket
				-cijena
			procesor:
				-naziv
				-model
				-soket
				-cijena
			graficka kartica:
				-naziv
				-model
				-Vram memorija
				-cijena 
			Ram:
				-naziv
				-model
				-kolicinarama
				-cijena
			hladnjaci:
				-naziv
				-model
				-cijena
			kuciste:
				-naziv 
				-model
				-cijena 			

		Tip1
		 -procesor i maticna ploca
			 naziv char[30]
			 model char[30]
			 soket char[10]
			 cijena float

		Tip2
		 -graficka kartica i ram 
			naziv char [30]
			model char[30]
			Vram memorija int 
			cijena float

		Tip3
		 -hladnjaci i kucista 
			naziv char[30]
			model char [5]
			cijena 	float 
*/	
//glavni izbornik
void manu() {
	int select = -1;
	do {
		system("cls");
		printf("This is manu :\n");
		printf("1)Enter new product in werhaus.\n");
		printf("2)Delite product from werhaus.\n");
		printf("3)Show item in werhause.\n");
		printf("4)Sell item from werhause.\n");
		printf("5)Exit program.\n");
		printf("Enther the walue of line whic you wont to execute.\n");
		do {
			scanf(" %d", &select);
			if (select < 1 || select>5) {
				printf("Enter the right walue:\n");
			}
		} while (select < 1 || select>5);

			switch (select)
			{
			case 1:
				EnterManu();
				break;
			case 2:
				DeleteMenu();
				break;
			case 3:
				ShowMenu();
				break;
			case 4:
				SellMenu();
				break;
			case 5:
				//exit
				return;
				break;
			}
		
	} while (select > 0);
}

void EnterManu() {
	int select = -1;
	do {
		system("cls");
		printf("This is manu for entering new items.\n");
		printf("Select which item you wont to enter in werhouse.\n");
		printf("1)Procesor\n");
		printf("2)Graphic procesor\n");
		printf("3)RAM\n");
		printf("4)Coler\n");
		printf("5)Case\n");
		printf("6)MatherBoard\n");
		printf("If you wont exizt from program enter 7\n");
		
		do {
			scanf(" %d", &select);
			if (select < 1 || select>7) {
				printf("Enter the right walue:\n");
			}
		} while (select < 1 || select>7);

		switch (select)
		{
		case 1:
			//procesor
			EnterTheProductType1("Procesor");
			break;
		case 2:
			//grafika
			EnterTheProductType2("GraphichCard");
			break;
		case 3:
			//ram
			EnterTheProductType2("RAM");
			break;
		case 4:
			//hladnjak
			EnterTheProductType3("Cooler");
			break;
		case 5:
			//kuciste
			EnterTheProductType3("Chase");
			break;
		case 6:
			//matherboard
			EnterTheProductType1("Matherboard");
			break;
		case 7:
			//exizit 
			return ;
			break;
		}
	} while (select > 0);
}

void DeleteMenu() {
	int select = -1;
	int counter = 0;
	int check = -1;
	char nameOfDeleteItem[30];
	int idOfDeleteItem = -1;

	do {
		system("cls");
		printf("This is manu for entering new items.\n");
		printf("Select which item you wont to delite from werhouse.\n");
		printf("1)Procesor\n");
		printf("2)Graphic procesor\n");
		printf("3)RAM\n");
		printf("4)Coler\n");
		printf("5)Case\n");
		printf("6)MatherBoard\n");
		printf("If you wont exizt from program enter 7\n");

		do {
			scanf(" %d", &select);
			if (select < 1 || select>7) {
				printf("Enter the right walue:\n");
			}
		} while (select < 1 || select>7);
		if (select < 7) {
			printf("Enther the name of product you wont sell.\n");
			scanf(" %29s", &nameOfDeleteItem);
			printf("Enter the id of that item.\n");
			scanf(" %d", &idOfDeleteItem);
		}
		switch (select)
		{
		case 1:
			//procesor
			check = DeliteProcesors(nameOfDeleteItem, idOfDeleteItem, "Procesor.bin", &counter);
			break;
		case 2:
			//grafika
			check = DeliteRAMORGraphicCard(nameOfDeleteItem, idOfDeleteItem, "GraphichCard.bin", &counter);
			break;
		case 3:
			//ram
			check= DeliteRAMORGraphicCard(nameOfDeleteItem, idOfDeleteItem, "RAM.bin", &counter);
			break;
		case 4:
			//hladnjak
			check=DeliteChaseOrColer(nameOfDeleteItem, idOfDeleteItem, "Cooler.bin", &counter);
			break;
		case 5:
			//kuciste
			check = DeliteChaseOrColer(nameOfDeleteItem, idOfDeleteItem, "Chase.bin", &counter);
			break;
		case 6:
			//matherboard
			check = DeliteMatherboard(nameOfDeleteItem, idOfDeleteItem, "Matherboard.bin", &counter);
			break;
		case 7:
			//exizit 
			return;
			break;
		}
		//cheking is item deleted from werhouse
		if (check == -1) {
			printf("Item is not found. Try again");
		}
		else {
			printf("Item is deleted.\n");
		}
		check = -1;
		counter = 0;
		_getch();
	} while (select > 0);
}

void ShowMenu() {
	int select = -1;
	int counter=0;
	PRODUCT_TYPE1* Procesor=NULL;
	PRODUCT_TYPE1* Matherboard = NULL;
	PRODUCT_TYPE2* GraphichCard = NULL;
	PRODUCT_TYPE2* RAM = NULL;
	PRODUCT_TYPE3* Coler = NULL;
	PRODUCT_TYPE3* Case = NULL;
	do {
		system("cls");
		printf("This is manu for Showing items.\n");
		printf("1)Procesor\n");
		printf("2)Graphic Card\n");
		printf("3)RAM\n");
		printf("4)Coler\n");
		printf("5)Case\n");
		printf("6)MatherBoard\n");
		printf("If you wont exizt from program enter 7\n");

		do {
			scanf(" %d", &select);
			if (select < 1 || select>7) {
				printf("Enter the right walue:\n");
			}
		} while (select < 1 || select>7);

		switch (select)
		{
		case 1:
			Procesor = GetingProductType1(Procesor, &counter, "Procesor.bin");
			if(Procesor==NULL){
				printf("Fail.");
				exit(EXIT_FAILURE);
			}
			Procesor = BubleSortProcesorsAndMatherboard(Procesor, &counter);
			PrintAllProductsProcesorsAndMatherboard(Procesor,"Procesor.bin",counter);
			free(Procesor);
			counter = 0;
			break;
		case 2:
			GraphichCard = GetingProductType2(GraphichCard, &counter, "GraphichCard.bin");
			if (GraphichCard == NULL) {
				printf("Fail.");
				exit(EXIT_FAILURE);
			}
			GraphichCard = BubleSortedGraphichCardAndRAM(GraphichCard,&counter);
			PrintAllProductsGraphichCardAndRAM(GraphichCard,"GraphichCard.bin",counter);
			free(GraphichCard);
			counter = 0;
			break;
		case 3:
			RAM = GetingProductType2(RAM, &counter, "RAM.bin");
			if (RAM == NULL) {
				printf("Fail.");
				exit(EXIT_FAILURE);
			}
			RAM = BubleSortedGraphichCardAndRAM(RAM, &counter);
			PrintAllProductsGraphichCardAndRAM(RAM, "RAM.bin", counter);
			free(RAM);
			counter = 0;
			break;
		case 4:
			Coler = GetingProductType3(Coler, &counter, "Cooler.bin");
			if (Coler == NULL) {
				printf("Fail.");
				exit(EXIT_FAILURE);
			}
			Coler = BubleSorteCaseAndColer(Coler, &counter);
			PrintAllProductsCaseAndColer(Coler, "Cooler.bin", counter);
			free(Coler);
			counter = 0;
			break;
		case 5:
			Case = GetingProductType3(Case, &counter, "Chase.bin");
			if (Case == NULL) {
				printf("Fail.");
				exit(EXIT_FAILURE);
			}
			Case = BubleSorteCaseAndColer(Case, &counter);
			PrintAllProductsCaseAndColer(Case, "Chase.bin", counter);
			free(Case);
			counter = 0;
			break;
		case 6:
			Matherboard = GetingProductType1(Matherboard, &counter, "Matherboard.bin");
			if (Matherboard == NULL) {
				printf("Fail.");
				exit(EXIT_FAILURE);
			}
			Matherboard = BubleSortProcesorsAndMatherboard(Matherboard, &counter);
			PrintAllProductsProcesorsAndMatherboard(Matherboard, "Matherboard.bin", counter);
			free(Matherboard);
			counter = 0;
			break;
		case 7:
			//exizit 
			return;
			break;
		}
	} while (select > 0);
}

void SellMenu() {
	int select = -1;
	char nameOfSearchItem[30];
	int idOfSearchItem=-1;
	int check = -1;
	int counter = 0;
	do {
		system("cls");
		printf("This is manu for Sell items.\n");
		printf("1)Procesor\n");
		printf("2)Graphic procesor\n");
		printf("3)RAM\n");
		printf("4)Coler\n");
		printf("5)Case\n");
		printf("6)Matherboard\n");
		printf("If you wont exizt from program enter 7\n");
		do {
			scanf(" %d", &select);
			if (select < 1 || select>7) {
				printf("Enter the right walue:\n");
			}
		} while (select < 1 || select>7);
		if (select < 7) {
			printf("Enther the name of product you wont sell.\n");
			scanf(" %29s", &nameOfSearchItem);
			printf("Enter the id of that item.\n");
			scanf(" %d", &idOfSearchItem);
		}
		counter = 0;
		switch (select)
		{
		case 1:
			/*
				removing quantiti of procesor from werhouse if the item exists. 
			*/
			check = SellProcesorsAndMatherboard(nameOfSearchItem, idOfSearchItem, "Procesor.bin",&counter);
			if (check > 0) {
				printf("The Purches is succesfull.\n");
			}
			else {
				printf("The purches is not succesfull.Try again.\n");
			}
			check = -1;
			break;
		case 2:
			//grafika
			check = SellGraphichCardAndRAM(nameOfSearchItem, idOfSearchItem, "GraphichCard.bin", &counter);
			if (check > 0) {
				printf("The Purches is succesfull.\n");
			}
			else {
				printf("The purches is not succesfull.Try again.\n");
			}
			check = -1;
			break;
		case 3:
			//ram
			check = SellGraphichCardAndRAM(nameOfSearchItem, idOfSearchItem, "RAM.bin", &counter);
			if (check > 0) {
				printf("The Purches is succesfull.\n");
			}
			else {
				printf("The purches is not succesfull.Try again.\n");
			}
			check = -1;
			break;
			break;
		case 4:
			//hladnjak
			check = SellCaseAndColer(nameOfSearchItem,idOfSearchItem,"Cooler.bin",&counter);
			if (check > 0) {
				printf("The Purches is succesfull.\n");
			}
			else {
				printf("The purches is not succesfull.Try again.\n");
			}
			check = -1;
			break;
		case 5:
			//kuciste
			check = SellCaseAndColer(nameOfSearchItem, idOfSearchItem, "Chase.bin", &counter);
			if (check > 0) {
				printf("The Purches is succesfull.\n");
			}
			else {
				printf("The purches is not succesfull.Try again.\n");
			}
			check = -1;
			break;
		case 6:
			check = SellProcesorsAndMatherboard(nameOfSearchItem, idOfSearchItem,"Matherboard.bin", &counter);
			if (check > 0) {
				printf("The Purches is succesfull.\n");
			}
			else {
				printf("The purches is not succesfull.Try again.\n");
			}
			check = -1;
			break;
		case 7:
			//exizit 
			return;
			break;
		}
		_getch();
	} while (select > 0);
}

void CreatingFiles() {
	FILE* Procesor, * Matherboard, * Chase;
	FILE* Cooler, * GraphichCard, * RAM;
	Procesor = fopen("Procesor.bin", "rb+");
	if (Procesor == NULL) {
		Procesor = fopen("Procesor.bin", "wb+");
		fclose(Procesor);
	}
	Matherboard = fopen("Matherboard.bin", "rb+");
	if (Matherboard == NULL) {
		Matherboard = fopen("Matherboard.bin", "wb+");
		fclose(Matherboard);
	}
	Chase = fopen("Chase.bin", "rb+");
	if (Chase == NULL) {
		Chase = fopen("Chase.bin", "wb+");
		fclose(Chase);
	}
	Cooler = fopen("Cooler.bin", "rb+");
	if (Cooler == NULL) {
		Cooler = fopen("Cooler.bin", "wb+");
		fclose(Cooler);
	}
	GraphichCard = fopen("GraphichCard.bin", "rb+");
	if (GraphichCard == NULL) {
		GraphichCard = fopen("GraphichCard.bin", "wb+");
		fclose(GraphichCard);
	}
	RAM = fopen("RAM.bin", "rb+");
	if (RAM == NULL) {
		RAM = fopen("RAM.bin", "wb+");
		fclose(RAM);
	}
}

void EnterTheProductType1(char FileName[30]) {
	//type 1 product 
	int temp = -1;
	int *quantity ;
	quantity = &temp;
	FILE *file = NULL;
	if ((strcmp(FileName,"Procesor")==0)) {
		//enter the procesosr
		PRODUCT_TYPE1* Procesors;
		file= fopen("Procesor.bin", "rb+");
		
		rewind(file);
		fread(quantity, sizeof(int), 1, file);
		if ((*quantity) < 0) {
			*quantity = 1;
		}
		else {
			(*quantity)++;	
		}
		rewind(file);
		fwrite(quantity, sizeof(int), 1, file);
		Procesors= (PRODUCT_TYPE1*)calloc(1, sizeof(PRODUCT_TYPE1));
		if (Procesors == NULL) {
			perror("No more space for new product.\n");
			exit(EXIT_FAILURE);
		}
		else {
			printf("Enter the name of processor:\n");
			scanf(" %29s", &Procesors->name);
			printf("Enther the type of procesor:\n");
			scanf(" %29s", &Procesors->type);
			printf("Enther the socket of procesor:\n");
			scanf(" %9s", &Procesors->soket);
			printf("Enther the price of procesor:\n");
			scanf(" %f", &Procesors->price);
			printf("Enther the quantity of procesor:\n");
			scanf(" %d", &Procesors->quantity);
			Procesors->id = *(quantity);
			fseek(file, 0, SEEK_END);
			fwrite(Procesors, sizeof(PRODUCT_TYPE1), 1, file);
		}
		fclose(file);
		free(Procesors);
	}
	else {
		PRODUCT_TYPE1* Matherboard;
		file = fopen("Matherboard.bin", "rb+");
		rewind(file);
		fread(quantity, sizeof(int), 1, file);
		if ((*quantity) < 0) {
			*quantity = 1;
		}
		else {
			(*quantity)++;
		}
		rewind(file);
		fwrite(quantity, sizeof(int), 1, file);

		Matherboard = (PRODUCT_TYPE1*)calloc(1, sizeof(PRODUCT_TYPE1));
		if (Matherboard == NULL) {
			perror("No more space for new product.\n");
			exit(EXIT_FAILURE);
		}
		else {
			printf("Enter the name of Matherboard:\n");
			scanf(" %29s", &Matherboard->name);
			printf("Enther the type of Matherboard:\n");
			scanf(" %29s", &Matherboard->type);
			printf("Enther the socket of Matherboard:\n");
			scanf(" %9s", &Matherboard->soket);
			printf("Enther the price of Matherboard:\n");
			scanf(" %f", &Matherboard->price);
			printf("Enther the quantity of Matherboard:\n");
			scanf(" %d", &Matherboard->quantity);
			Matherboard->id = *(quantity);
			fseek(file, 0, SEEK_END);
			fwrite(Matherboard, sizeof(PRODUCT_TYPE1), 1, file);
		}
		fclose(file);
		free(Matherboard);
	}
	return;
}

void EnterTheProductType2(char FileName[30]) {
	int temp = -1;
	int* quantity;
	quantity = &temp;
	FILE* file = NULL;
	if ((strcmp(FileName,"GraphichCard"))==0) {
		//enter the GraphichCard
		PRODUCT_TYPE2* GraphichCard=NULL;
		file = fopen("GraphichCard.bin", "rb+");
		if (file == NULL) {
			perror("Fali.");
			exit(EXIT_FAILURE);
		}


		GraphichCard = (PRODUCT_TYPE2*)calloc(1, sizeof(PRODUCT_TYPE2));
		if (GraphichCard == NULL) {
			perror("No more space for new product.\n");
			exit(EXIT_FAILURE);
		}
		else {
			rewind(file);
			fread(quantity, sizeof(int), 1, file);
			(*quantity)++;
			rewind(file);
			fwrite(quantity, sizeof(int), 1, file);

			printf("Enter the name of GraphichCard:\n");
			scanf(" %29s", &GraphichCard->name);
			printf("Enther the type of GraphichCard:\n");
			scanf(" %29s", &GraphichCard->type);
			printf("Enther the VRAM of GraphichCard:\n");
			scanf(" %d", &GraphichCard->VRAM);
			printf("Enther the price of GraphichCard:\n");
			scanf(" %f", &GraphichCard->price);
			printf("Enther the quantity of GraphichCard:\n");
			scanf(" %d", &GraphichCard->quantity);
			GraphichCard->id = *(quantity);
			fseek(file, 0, SEEK_END);
			fwrite(GraphichCard, sizeof(PRODUCT_TYPE2), 1, file);
			fclose(file);
			free(GraphichCard);
			
		}
		
	}
	if((strcmp(FileName,"RAM"))==0) {
		//enter the procesor
		PRODUCT_TYPE2* RAM;
		file = fopen("RAM.bin", "rb+");

		rewind(file);
		fread(quantity, sizeof(int), 1, file);
		if ((*quantity) < 0) {
			*quantity = 1;
		}
		else {
			(*quantity)++;
		}
		rewind(file);
		fwrite(quantity, sizeof(int), 1, file);
		RAM = (PRODUCT_TYPE2*)calloc(1, sizeof(PRODUCT_TYPE2));
		if (RAM == NULL) {
			perror("No more space for new product.\n");
			exit(EXIT_FAILURE);
		}
		else {
			printf("Enter the name of RAM:\n");
			scanf(" %29s", &RAM->name);
			printf("Enther the type of RAM:\n");
			scanf(" %29s", &RAM->type);
			printf("Enther the capacity of RAM:\n");
			scanf(" %d", &RAM->VRAM);
			printf("Enther the price of RAM:\n");
			scanf(" %f", &RAM->price);
			printf("Enther the quantity of RAM:\n");
			scanf(" %d", &RAM->quantity);
			RAM->id = *(quantity);
			fseek(file, 0, SEEK_END);
			fwrite(RAM, sizeof(PRODUCT_TYPE2), 1, file);
			fclose(file);
			free(RAM);
			
		}
	}
	return;
}

void EnterTheProductType3(char FileName[30]) {
	int temp = -1;
	int* quantity;
	quantity = &temp;
	FILE* file = NULL;
	if ((strcmp(FileName, "Chase")) == 0) {
		//enter the GraphichCard
		PRODUCT_TYPE3* Chase = NULL;
		file = fopen("Chase.bin", "rb+");
		if (file == NULL) {
			perror("Fali.");
			exit(EXIT_FAILURE);
		}

		Chase = (PRODUCT_TYPE3*)calloc(1, sizeof(PRODUCT_TYPE3));
		if (Chase == NULL) {
			perror("No more space for new product.\n");
			exit(EXIT_FAILURE);
		}
		else {
			rewind(file);
			fread(quantity, sizeof(int), 1, file);
			(*quantity)++;
			rewind(file);
			fwrite(quantity, sizeof(int), 1, file);
		
			printf("Enter the name of Chase:\n");
			scanf(" %29s", &Chase->name);
			printf("Enther the type of Chase:\n");
			scanf(" %29s", &Chase->type);
			printf("Enther the price of Chase:\n");
			scanf(" %f", &Chase->price);
			printf("Enther the quantity of Chase:\n");
			scanf(" %d", &Chase->quantity);
			Chase->id = *(quantity);
			fseek(file, 0, SEEK_END);
			fwrite(Chase, sizeof(PRODUCT_TYPE3), 1, file);
			fclose(file);
			free(Chase);
		}
	}
	if ((strcmp(FileName, "Cooler")) == 0) {
		PRODUCT_TYPE3* Cooler = NULL;
		file = fopen("Cooler.bin", "rb+");
		if (file == NULL) {
			perror("Fali.");
			exit(EXIT_FAILURE);
		}

		Cooler = (PRODUCT_TYPE3*)calloc(1, sizeof(PRODUCT_TYPE3));
		if (Cooler == NULL) {
			perror("No more space for new product.\n");
			exit(EXIT_FAILURE);
		}
		else {
			rewind(file);
			fread(quantity, sizeof(int), 1, file);
			(*quantity)++;
			rewind(file);
			fwrite(quantity, sizeof(int), 1, file);

			printf("Enter the name of Cooler:\n");
			scanf(" %29s", &Cooler->name);
			printf("Enther the type of Cooler:\n");
			scanf(" %29s", &Cooler->type);
			printf("Enther the price of Cooler:\n");
			scanf(" %f", &Cooler->price);
			printf("Enther the quantity of Cooler:\n");
			scanf(" %d", &Cooler->quantity);
			Cooler->id = *(quantity);
			fseek(file, 0, SEEK_END);
			fwrite(Cooler, sizeof(PRODUCT_TYPE3), 1, file);
			fclose(file);
			free(Cooler);
		}
	}
	return;
}

//geting from files products
PRODUCT_TYPE1* GetingProductType1(PRODUCT_TYPE1*Product,int* counter,char*fileName) {//dohvacanje procesora i maticne ploce
	FILE* file=NULL;
	file = fopen(fileName, "rb+");
	if (file == NULL) {
		printf("It is not possible to open file.");
		exit(EXIT_FAILURE);
	}
	else {
		rewind(file);
		fread(counter, sizeof(int), 1, file);
		Product = (PRODUCT_TYPE1*)calloc(*counter, sizeof(PRODUCT_TYPE1));
		if (Product == NULL) {
			printf("That is too mach products for memory.");
			exit(EXIT_FAILURE);
		}
		else {
			fread(Product, sizeof(PRODUCT_TYPE1), *counter, file);
			fclose(file);
			return Product;
		}
	}
}

PRODUCT_TYPE2* GetingProductType2(PRODUCT_TYPE2* Product, int* counter, char* fileName) {//dohvacanje graficka kartica i ram 
	FILE* file = NULL;
	file = fopen(fileName, "rb+");
	if (file == NULL) {
		printf("It is not possible to open file.");
		exit(EXIT_FAILURE);
	}
	else {
		rewind(file);
		fread(counter, sizeof(int), 1, file);
		Product = (PRODUCT_TYPE2*)calloc(*counter, sizeof(PRODUCT_TYPE2));
		if (Product == NULL) {
			printf("That is too mach products for memory.");
			exit(EXIT_FAILURE);
		}
		else {
			fread(Product, sizeof(PRODUCT_TYPE2), *counter, file);
			fclose(file);
			return Product;
		}
	}
}

PRODUCT_TYPE3* GetingProductType3(PRODUCT_TYPE3* Product, int* counter, char* fileName) {//dohvacanje -hladnjaci i kucista 
	FILE* file = NULL;
	file = fopen(fileName, "rb+");
	if (file == NULL) {
		printf("It is not possible to open file.");
		exit(EXIT_FAILURE);
	}
	else {
		rewind(file);
		fread(counter, sizeof(int), 1, file);
		
		Product = (PRODUCT_TYPE3*)calloc(*counter, sizeof(PRODUCT_TYPE3));
		if (Product == NULL) {
			printf("That is too mach products for memory.");
			exit(EXIT_FAILURE);
		}
		else {
			fread(Product, sizeof(PRODUCT_TYPE3), *counter, file);
			fclose(file);
			return Product;
		}
	}
}

//Printign on screen all items
//If no item in the file program print "Ther is no item for show."
void PrintAllProductsProcesorsAndMatherboard(PRODUCT_TYPE1* Product,char* fileName,int counter) {
	FILE* file = NULL;
	file = fopen(fileName, "rb+");
	if (file == NULL) {
		printf("It is not possible to open file.");
		exit(EXIT_FAILURE);
	}
	else {
		if (strcmp("Procesor.bin", fileName)==0) {	
			if (counter != 0) {
				for (int i = 0; i < counter; i++) {
					printf("\nName of procesor:%s\nSoket of procesor:%s\nPrice of procesor:%f\nQuantity:%d\nId of product:%d\n",
						(Product + i)->name,
						(Product + i)->soket,
						(Product + i)->price,
						(Product + i)->quantity,
						(Product + i)->id);
				}
			}
			else {
				printf("Ther is no item for show.");
			}
		}
		else {
			if (counter != 0) {
				for (int i = 0; i < counter; i++) {
					printf("\nName of MatherBoard:%s\nSoket of MatherBoard:%s\nPrice of MatherBoard:%f\nQuantity:%d\nId of product:%d\n",
						(Product + i)->name,
						(Product + i)->soket,
						(Product + i)->price,
						(Product + i)->quantity,
						(Product + i)->id);
				}
			}
			else {
				printf("Ther is no item for show.");
			}
		}
	}
	fclose(file);
	_getch();
}

void PrintAllProductsGraphichCardAndRAM(PRODUCT_TYPE2* Product, char* fileName, int counter) {
	FILE* file = NULL;
	file = fopen(fileName, "rb+");
	if (file == NULL) {
		printf("It is not possible to open file.");
		exit(EXIT_FAILURE);
	}
	else {
		if (strcmp("GraphichCard.bin", fileName) == 0) {
			if (counter != 0) {
				for (int i = 0; i < counter; i++) {

					printf("\nName of GraphichCard:%s\nType of GraphichCard:%s\n VRAM:%d\nPrice of GraphichCard:%f\nQuantity:%d\nId of product:%d\n",
						(Product + i)->name,
						(Product + i)->type,
						(Product + i)->VRAM,
						(Product + i)->price,
						(Product + i)->quantity,
						(Product + i)->id);
				}
			}else{ 
				printf("Ther is no item for show.");
			}
		}
		else {
			if (counter != 0) {
				for (int i = 0; i < counter; i++) {
					printf("\nName of RAM:%s\nType of RAM:%s\n RAM GB:%d\nPrice of RAM:%f\nQuantity:%d\nId of product:%d\n",
						(Product + i)->name,
						(Product + i)->type,
						(Product + i)->VRAM,
						(Product + i)->price,
						(Product + i)->quantity,
						(Product + i)->id);
				}
			}
			else {
				printf("Ther is no item for show.");
			}
		}
	}
	fclose(file);
	_getch();
}

void PrintAllProductsCaseAndColer(PRODUCT_TYPE3* Product, char* fileName, int counter) {
	FILE* file = NULL;
	file = fopen(fileName, "rb+");
	if (file == NULL) {
		printf("It is not possible to open file.");
		exit(EXIT_FAILURE);
	}
	else {
		if (strcmp("Chase.bin", fileName) == 0) {
			if (counter != 0) {
				for (int i = 0; i < counter; i++) {
					printf("\nName of Chase:%s\nType of Chase:%s\nPrice of Chase:%f\nQuantity:%d\nId of product:%d\n",
						(Product + i)->name,
						(Product + i)->type,
						(Product + i)->price,
						(Product + i)->quantity,
						(Product + i)->id);
				}
			}
			else {
				printf("Ther is no item for show.");
			}

		}
		else {
			if (counter != 0) {
				for (int i = 0; i < counter; i++) {
					printf("\nName of Cooler:%s\nType of Cooler:%s\nPrice of Cooler:%f\nQuantity:%d\nId of product:%d\n",
						(Product + i)->name,
						(Product + i)->type,
						(Product + i)->price,
						(Product + i)->quantity,
						(Product + i)->id);
				}
			}
			else {
				printf("Ther is no item for show.");
			}
		}
	}
	fclose(file);
	_getch();
}

//buble sort metods for all prodcts
PRODUCT_TYPE1* BubleSortProcesorsAndMatherboard(PRODUCT_TYPE1* Product, int* counter) {
	PRODUCT_TYPE1 Swap;

	for (int i = 0; i <(*counter )- 1; i++)
	{
		for (int j = 0; j < (*counter) - 1 - i; j++)
		{
			if ((Product + j + 1)->price < (Product + j)->price) {
				//save in swap from (Product + j + 1)
				strcpy(Swap.name, (Product + j + 1)->name);
				strcpy(Swap.type, (Product + j + 1)->type);
				strcpy(Swap.soket, (Product + j + 1)->soket);
				Swap.price = (Product + j + 1)->price;
				Swap.quantity = (Product + j + 1)->quantity;
				Swap.id = (Product + j + 1)->id;

				//save in  (Product + j + 1) from  (Product + j)
				strcpy((Product + j + 1)->name, (Product + j)->name);
				strcpy((Product + j + 1)->type, (Product + j)->type);
				strcpy((Product + j + 1)->soket, (Product + j)->soket);
				(Product + j + 1)->price = (Product + j)->price;
				(Product + j + 1)->quantity = (Product + j)->quantity;
				(Product + j + 1)->id = (Product + j)->id;

				//save in (Product + j) from swap
				strcpy((Product + j)->name, Swap.name);
				strcpy((Product + j)->type, Swap.type);
				strcpy((Product + j)->soket, Swap.soket);
				(Product + j)->price = Swap.price;
				(Product + j)->quantity = Swap.quantity;
				(Product + j)->id = Swap.id;
			}
		}
	}
	return Product;
}

PRODUCT_TYPE2* BubleSortedGraphichCardAndRAM(PRODUCT_TYPE2* Product, int* counter) {
	PRODUCT_TYPE2 Swap;

	for (int i = 0; i < (*counter) - 1; i++)
	{
		for (int j = 0; j < (*counter) - 1 - i; j++)
		{
			if ((Product + j + 1)->price < (Product + j)->price) {
				//save in swap from (Product + j + 1)
				strcpy(Swap.name, (Product + j + 1)->name);
				strcpy(Swap.type, (Product + j + 1)->type);
				Swap.VRAM = (Product + j + 1)->VRAM;
				Swap.price = (Product + j + 1)->price;
				Swap.quantity = (Product + j + 1)->quantity;
				Swap.id = (Product + j + 1)->id;

				//save in  (Product + j + 1) from  (Product + j)
				strcpy((Product + j + 1)->name, (Product + j)->name);
				strcpy((Product + j + 1)->type, (Product + j)->type);
				(Product + j + 1)->VRAM = (Product + j)->VRAM;
				(Product + j + 1)->price = (Product + j)->price;
				(Product + j + 1)->quantity = (Product + j)->quantity;
				(Product + j + 1)->id = (Product + j)->id;

				//save in (Product + j) from swap
				strcpy((Product + j)->name, Swap.name);
				strcpy((Product + j)->type, Swap.type);
				(Product + j)->VRAM = Swap.VRAM;
				(Product + j)->price = Swap.price;
				(Product + j)->quantity = Swap.quantity;
				(Product + j)->id = Swap.id;
			}
		}
	}
	return Product;
}

PRODUCT_TYPE3* BubleSorteCaseAndColer(PRODUCT_TYPE3* Product, int* counter) {
	PRODUCT_TYPE3 Swap;

	for (int i = 0; i < (*counter) - 1; i++)
	{
		for (int j = 0; j < (*counter) - 1 - i; j++)
		{
			if ((Product + j + 1)->price < (Product + j)->price) {
				//save in swap from (Product + j + 1)
				strcpy(Swap.name, (Product + j + 1)->name);
				strcpy(Swap.type, (Product + j + 1)->type);
				Swap.price = (Product + j + 1)->price;
				Swap.quantity = (Product + j + 1)->quantity;
				Swap.id = (Product + j + 1)->id;

				//save in  (Product + j + 1) from  (Product + j)
				strcpy((Product + j + 1)->name, (Product + j)->name);
				strcpy((Product + j + 1)->type, (Product + j)->type);
				(Product + j + 1)->price = (Product + j)->price;
				(Product + j + 1)->quantity = (Product + j)->quantity;
				(Product + j + 1)->id = (Product + j)->id;

				//save in (Product + j) from swap
				strcpy((Product + j)->name, Swap.name);
				strcpy((Product + j)->type, Swap.type);
				(Product + j)->price = Swap.price;
				(Product + j)->quantity = Swap.quantity;
				(Product + j)->id = Swap.id;
			}
		}
	}
	return Product;
}

//Selling products 
int SellProcesorsAndMatherboard(char* nameOfSearchItem, int idOfSearchItem, char* fileName,int *counter) {
	int sellQuantity=0;
	FILE* file = NULL;
	int temp = *(counter);
	if((strcmp("Procesor.bin",fileName))==0){
		PRODUCT_TYPE1* Procesor = NULL;
		Procesor = GetingProductType1(Procesor, counter, "Procesor.bin");
		if (Procesor == NULL) {
			printf("Fail.");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < *(counter); i++) {
			if ((strcmp((Procesor + i)->name, nameOfSearchItem) == 0) && (Procesor + i)->id == idOfSearchItem) {
				printf("Item is found.\n");
				printf("\nName of procesor:%s\nSoket of procesor:%s\nPrice of procesor:%f\nQuantity:%d\nId of product:%d\n",
					(Procesor + i)->name,
					(Procesor + i)->soket,
					(Procesor + i)->price,
					(Procesor + i)->quantity,
					(Procesor + i)->id);
				printf("How much processor you wont sell:\n");
				scanf(" %d", &sellQuantity);
				if (sellQuantity > (Procesor + i)->quantity) {
					printf("That purches for this processor is not possible\n");
					free(Procesor);
					return -1;
				}
				else {
					(Procesor + i)->quantity = (Procesor + i)->quantity - sellQuantity;
					printf("New quantity is %d\n", (Procesor + i)->quantity);
					break;
				}
			}
		}
		//entering new value of quantity in the file 
		remove("Procesor.bin");
		file=fopen("Procesor.bin", "wb");
		if (file == NULL) {
			perror("Otvaranje dat:");
			exit(EXIT_FAILURE);
		}
		else {
			rewind(file);
			fwrite(counter, sizeof(int), 1, file);
			fseek(file, 4, SEEK_SET);
			for (int i = 0; i < (*counter); i++) {
				fwrite((Procesor + i), sizeof(PRODUCT_TYPE1), 1, file);
			}
		}
		fclose(file);
		free(Procesor);
		return 1;
	}
	else {
		PRODUCT_TYPE1* Matherboard = NULL;
		Matherboard = GetingProductType1(Matherboard, counter, "Matherboard.bin");
		if (Matherboard == NULL) {
			printf("Fail.");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < *(counter); i++) {
			if ((strcmp((Matherboard + i)->name, nameOfSearchItem) == 0) && (Matherboard + i)->id == idOfSearchItem) {
				printf("Item is found.\n");
				printf("\nName of Matherboard:%s\nSoket of Matherboard:%s\nPrice of Matherboard:%f\nQuantity:%d\nId of product:%d\n",
					(Matherboard + i)->name,
					(Matherboard + i)->soket,
					(Matherboard + i)->price,
					(Matherboard + i)->quantity,
					(Matherboard + i)->id);
				printf("How much Matherboard you wont sell:\n");
				scanf(" %d", &sellQuantity);
				if (sellQuantity > (Matherboard + i)->quantity) {
					printf("That purches for this Matherboard is not possible\n");
					free(Matherboard);
					return -1;
				}
				else {
					(Matherboard + i)->quantity = (Matherboard + i)->quantity - sellQuantity;
					printf("New quantity is %d\n", (Matherboard + i)->quantity);
					break;
				}
			}
		}
		//entering new value of quantity in the file 
		remove("Matherboard.bin");
		file = fopen("Matherboard.bin", "wb");
		if (file == NULL) {
			perror("Otvaranje dat:");
			exit(EXIT_FAILURE);
		}
		else {
			rewind(file);
			fwrite(counter, sizeof(int), 1, file);
			fseek(file, 4, SEEK_SET);
			for (int i = 0; i < (*counter); i++) {
				fwrite((Matherboard + i), sizeof(PRODUCT_TYPE1), 1, file);
			}
		}
		fclose(file);
		free(Matherboard);
		return 1;
	}
	return -1;
}

int SellGraphichCardAndRAM(char* nameOfSearchItem, int idOfSearchItem, char* fileName, int* counter) {
	int sellQuantity = 0;
	FILE* file = NULL;
	int temp = *(counter);
	if ((strcmp("GraphichCard.bin", fileName)) == 0) {
		PRODUCT_TYPE2* GraphichCard = NULL;
		GraphichCard = GetingProductType2(GraphichCard, counter, "GraphichCard.bin");
		if (GraphichCard == NULL) {
			printf("Fail.");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < *(counter); i++) {
			if ((strcmp((GraphichCard + i)->name, nameOfSearchItem) == 0) && (GraphichCard + i)->id == idOfSearchItem) {
				printf("\nItem is found.\n");
				printf("Name of GraphichCard:%s\nType of GraphichCard:%s\n VRAM:%d\nPrice of GraphichCard:%f\nQuantity:%d\nId of product:%d\n",
					(GraphichCard + i)->name,
					(GraphichCard + i)->type,
					(GraphichCard + i)->VRAM,
					(GraphichCard + i)->price,
					(GraphichCard + i)->quantity,
					(GraphichCard + i)->id);
				printf("How much GraphichCard you wont sell:\n");
				scanf(" %d", &sellQuantity);
				if (sellQuantity > (GraphichCard + i)->quantity) {
					printf("That purches for this GraphichCard is not possible\n");
					free(GraphichCard);
					return -1;
				}
				else {
					(GraphichCard + i)->quantity = (GraphichCard + i)->quantity - sellQuantity;
					printf("New quantity is %d\n", (GraphichCard + i)->quantity);
					break;
				}
			}
		}
		//entering new value of quantity in the file 
		remove("GraphichCard.bin");
		file = fopen("GraphichCard.bin", "wb");
		if (file == NULL) {
			perror("Opening dat:");
			exit(EXIT_FAILURE);
		}
		else {
			rewind(file);
			fwrite(counter, sizeof(int), 1, file);
			fseek(file, 4, SEEK_SET);
			for (int i = 0; i < (*counter); i++) {
				fwrite((GraphichCard + i), sizeof(PRODUCT_TYPE2), 1, file);
			}
		}
		fclose(file);
		free(GraphichCard);
		return 1;
	}
	else {
		PRODUCT_TYPE2* RAM = NULL;
		RAM = GetingProductType2(RAM, counter, "RAM.bin");
		if (RAM == NULL) {
			printf("Fail.");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < *(counter); i++) {
			if ((strcmp((RAM + i)->name, nameOfSearchItem) == 0) && (RAM + i)->id == idOfSearchItem) {
				printf("\nItem is found.\n");
				printf("Name of RAM:%s\nType of RAM:%s\n Gb of RAM memory:%d\nPrice of RAM:%f\nQuantity:%d\nId of product:%d\n",
					(RAM + i)->name,
					(RAM + i)->type,
					(RAM + i)->VRAM,
					(RAM + i)->price,
					(RAM + i)->quantity,
					(RAM + i)->id);
				printf("How much GraphichCard you wont sell:\n");
				scanf(" %d", &sellQuantity);
				if (sellQuantity > (RAM + i)->quantity) {
					printf("That purches for this GraphichCard is not possible\n");
					free(RAM);
					return -1;
				}
				else {
					(RAM + i)->quantity = (RAM + i)->quantity - sellQuantity;
					printf("New quantity is %d\n", (RAM + i)->quantity);
					break;
				}
			}
		}
		//entering new value of quantity in the file 
		remove("RAM.bin");
		file = fopen("RAM.bin", "wb");
		if (file == NULL) {
			perror("Opening dat:");
			exit(EXIT_FAILURE);
		}
		else {
			rewind(file);
			fwrite(counter, sizeof(int), 1, file);
			fseek(file, 4, SEEK_SET);
			for (int i = 0; i < (*counter); i++) {
				fwrite((RAM + i), sizeof(PRODUCT_TYPE2), 1, file);
			}
		}
		fclose(file);
		free(RAM);
		return 1;
	}
	return -1;
}

int SellCaseAndColer(char* nameOfSearchItem, int idOfSearchItem, char* fileName, int* counter) {
	int sellQuantity = 0;
	FILE* file = NULL;
	int temp = *(counter);
	if ((strcmp("Chase.bin", fileName)) == 0) {
		PRODUCT_TYPE3* Chase = NULL;
		Chase = GetingProductType3(Chase, counter, "Chase.bin");
		if (Chase == NULL) {
			printf("Fail.");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < *(counter); i++) {
			if ((strcmp((Chase + i)->name, nameOfSearchItem) == 0) && (Chase + i)->id == idOfSearchItem) {
				printf("\nItem is found.\n");
				printf("\nName of Chase:%s\nType of Chase:%s\nPrice of Chase:%f\nQuantity:%d\nId of product:%d\n",
					(Chase + i)->name,
					(Chase + i)->type,
					(Chase + i)->price,
					(Chase + i)->quantity,
					(Chase + i)->id);
				printf("How much Chase you wont sell:\n");
				scanf(" %d", &sellQuantity);
				if (sellQuantity > (Chase + i)->quantity) {
					printf("That purches for this Chase is not possible\n");
					free(Chase);
					return -1;
				}
				else {
					(Chase + i)->quantity = (Chase + i)->quantity - sellQuantity;
					printf("New quantity is %d\n", (Chase + i)->quantity);
					break;
				}
			}
		}
		//entering new value of quantity in the file 
		remove("Chase.bin");
		file = fopen("Chase.bin", "wb");
		if (file == NULL) {
			perror("Opening dat:");
			exit(EXIT_FAILURE);
		}
		else {
			rewind(file);
			fwrite(counter, sizeof(int), 1, file);
			fseek(file, 4, SEEK_SET);
			for (int i = 0; i < (*counter); i++) {
				fwrite((Chase + i), sizeof(PRODUCT_TYPE3), 1, file);
			}
		}
		fclose(file);
		free(Chase);
		return 1;
	}
	else {
		PRODUCT_TYPE3* Cooler = NULL;
		Cooler = GetingProductType3(Cooler, counter, "Cooler.bin");
		if (Cooler == NULL) {
			printf("Fail.");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < *(counter); i++) {
			if ((strcmp((Cooler + i)->name, nameOfSearchItem) == 0) && (Cooler + i)->id == idOfSearchItem) {
				printf("\nItem is found.\n");
				printf("\nName of Cooler:%s\nType of Cooler:%s\nPrice of Cooler:%f\nQuantity:%d\nId of product:%d\n",
					(Cooler + i)->name,
					(Cooler + i)->type,
					(Cooler + i)->price,
					(Cooler + i)->quantity,
					(Cooler + i)->id);
				printf("How much Cooler you wont sell:\n");
				scanf(" %d", &sellQuantity);
				if (sellQuantity > (Cooler + i)->quantity) {
					printf("That purches for this Chase is not possible\n");
					free(Cooler);
					return -1;
				}
				else {
					(Cooler + i)->quantity = (Cooler + i)->quantity - sellQuantity;
					printf("New quantity is %d\n", (Cooler + i)->quantity);
					break;
				}
			}
		}
		//entering new value of quantity in the file 
		remove("Cooler.bin");
		file = fopen("Cooler.bin", "wb");
		if (file == NULL) {
			perror("Opening dat:");
			exit(EXIT_FAILURE);
		}
		else {
			rewind(file);
			fwrite(counter, sizeof(int), 1, file);
			fseek(file, 4, SEEK_SET);
			for (int i = 0; i < (*counter); i++) {
				fwrite((Cooler + i), sizeof(PRODUCT_TYPE3), 1, file);
			}
		}
		fclose(file);
		free(Cooler);
		return 1;
	}
	return -1;
}

//Deliting items
int DeliteProcesors(char* nameOfItem, int idOfItem, char* fileName, int* counter) {
	FILE* file = NULL;
	int temp = *(counter);
	int flag = 0;
	PRODUCT_TYPE1* Procesor = NULL;
	Procesor = GetingProductType1(Procesor, counter, "Procesor.bin");
	if (*(counter) == 0) {
		return -1;
	}
	if (Procesor == NULL) {
		printf("Fail.");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < *(counter); i++) {
		if ((strcmp((Procesor + i)->name, nameOfItem) == 0) && (Procesor + i)->id == idOfItem) {
			flag = 1;
		}
		//updating id becouse one item will be less in sistem
		if (flag == 1) {
			(Procesor + i)->id--;
		}
	}
	//chekinng if item is not in the list then other code is not nessesary to done.
	if (flag == 0) {
		free(Procesor);
		return -1;
	}
	//entering new value of quantity in the file 
	remove("Procesor.bin");
	file = fopen("Procesor.bin", "wb");
	if (file == NULL) {
		perror("Otvaranje dat:");
		exit(EXIT_FAILURE);
	}
	else {
		rewind(file);
		fwrite(counter, sizeof(int), 1, file);
		fseek(file, 4, SEEK_SET);
		for (int i = 0; i < (*counter); i++) {
			if ((strcmp((Procesor + i)->name, nameOfItem) == 0) && (Procesor + i)->id == idOfItem) {
				continue;
			}
			else {
				fwrite((Procesor + i), sizeof(PRODUCT_TYPE1), 1, file);
			}
		}
	}
	*(counter) = *(counter)-1;
	rewind(file);
	fwrite(counter, sizeof(int), 1, file);
	fclose(file);
	free(Procesor);
	return 1;
}

int DeliteMatherboard(char* nameOfItem, int idOfItem, char* fileName, int* counter) {
	FILE* file = NULL;
	int flag = 0;
	PRODUCT_TYPE1* Matherboard = NULL;
	Matherboard = GetingProductType1(Matherboard, counter, fileName);
	if (*(counter) == 0) {
		return -1;
	}
	if (Matherboard == NULL) {
		printf("Fail.");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < *(counter); i++) {
		if ((strcmp((Matherboard + i)->name, nameOfItem) == 0) && (Matherboard + i)->id == idOfItem) {
			flag = 1;
		}
		//updating id becouse one item will be less in sistem
		if (flag == 1) {
			(Matherboard + i)->id--;
		}
	}
	//chekinng if item is not in the list then other code is not nessesary to done.
	if (flag == 0) {
		free(Matherboard);
		return -1;
	}
	//entering new value of quantity in the file 
	remove(fileName);
	file = fopen(fileName, "wb");
	if (file == NULL) {
		perror("Otvaranje dat:");
		free(Matherboard);
		exit(EXIT_FAILURE);
	}
	else {
		rewind(file);
		fwrite(counter, sizeof(int), 1, file);
		fseek(file, 4, SEEK_SET);
		for (int i = 0; i < (*counter); i++) {
			if ((strcmp((Matherboard + i)->name, nameOfItem) == 0) && (Matherboard + i)->id == idOfItem) {
				continue;
			}
			else {
				fwrite((Matherboard + i), sizeof(PRODUCT_TYPE1), 1, file);
			}
		}
	}
	*(counter) = *(counter)-1;
	rewind(file);
	fwrite(counter, sizeof(int), 1, file);
	fclose(file);
	free(Matherboard);
	return 1;
}

int DeliteRAMORGraphicCard(char* nameOfItem, int idOfItem, char* fileName, int* counter) {
	FILE* file = NULL;
	int flag = 0;
	PRODUCT_TYPE2* Product = NULL;
	Product = GetingProductType2(Product, counter, fileName);
	if (*(counter) == 0) {
		return -1;
	}
	if (Product == NULL) {
		printf("Fail.");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < *(counter); i++) {
		if ((strcmp((Product + i)->name, nameOfItem) == 0) && (Product + i)->id == idOfItem) {
			flag = 1;
		}
		//updating id becouse one item will be less in sistem
		if (flag == 1) {
			(Product + i)->id--;
		}
	}
	//chekinng if item is not in the list then other code is not nessesary to done.
	if (flag == 0) {
		free(Product);
		return -1;
	}
	//entering new value of quantity in the file 
	remove(fileName);
	file = fopen(fileName, "wb");
	if (file == NULL) {
		perror("Otvaranje dat:");
		free(Product);
		exit(EXIT_FAILURE);
	}
	else {
		rewind(file);
		fwrite(counter, sizeof(int), 1, file);
		fseek(file, 4, SEEK_SET);
		for (int i = 0; i < (*counter); i++) {
			if ((strcmp((Product + i)->name, nameOfItem) == 0) && (Product + i)->id == idOfItem) {
				continue;
			}
			else {
				fwrite((Product + i), sizeof(PRODUCT_TYPE2), 1, file);
			}
		}
	}
	*(counter) = *(counter)-1;
	rewind(file);
	fwrite(counter, sizeof(int), 1, file);
	fclose(file);
	free(Product);
	return 1;
}

int DeliteChaseOrColer(char* nameOfItem, int idOfItem, char* fileName, int* counter) {
	FILE* file = NULL;
	int flag = 0;
	PRODUCT_TYPE3* Product = NULL;
	Product = GetingProductType3(Product, counter, fileName);
	if (*(counter) == 0) {
		return -1;
	}
	if (Product == NULL) {
		printf("Fail.");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < *(counter); i++) {
		if ((strcmp((Product + i)->name, nameOfItem) == 0) && (Product + i)->id == idOfItem) {
			flag = 1;
		}
		//updating id becouse one item will be less in sistem
		if (flag == 1) {
			(Product + i)->id--;
		}
	}
	//chekinng if item is not in the list then other code is not nessesary to done.
	if (flag == 0) {
		free(Product);
		return -1;
	}
    //logic for deliting certen item from wherehouse
	remove(fileName);
	file = fopen(fileName, "wb");
	if (file == NULL) {
		perror("Otvaranje dat:");
		free(Product);
		exit(EXIT_FAILURE);
	}
	else {
		rewind(file);
		fwrite(counter, sizeof(int), 1, file);
		fseek(file, 4, SEEK_SET);
		for (int i = 0; i < (*counter); i++) {
			if ((strcmp((Product + i)->name, nameOfItem) == 0) && (Product + i)->id == idOfItem) {
				continue;
			}
			else {
				fwrite((Product + i), sizeof(PRODUCT_TYPE3), 1, file);
			}
		}
	}
	*(counter) = *(counter)-1;
	rewind(file);
	fwrite(counter, sizeof(int), 1, file);
	fclose(file);
	free(Product);
	return 1;
}
