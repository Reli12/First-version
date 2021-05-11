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

		switch (select)
		{
		case 1:
			//procesor
			break;
		case 2:
			//grafika
			break;
		case 3:
			//ram
			break;
		case 4:
			//hladnjak
			break;
		case 5:
			//kuciste
			break;
		case 6:
			//matherboard
			break;
		case 7:
			//exizit 
			return;
			break;
		}
	} while (select > 0);
}

void ShowMenu() {
	int select = -1;
	do {
		system("cls");
		printf("This is manu for Showing items.\n");
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
			/*
				prikaz svih procesora
					poredak procesora- po padajucim ili rastucim vrijednostima 
					pretraga- po nazivu
			*/
			break;
		case 2:
			//grafika
			break;
		case 3:
			//ram
			break;
		case 4:
			//hladnjak
			break;
		case 5:
			//kuciste
			break;
		case 6:
			//matherboard
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
	do {
		system("cls");
		printf("This is manu for Sell items.\n");
		printf("1)Procesor\n");
		printf("2)Graphic procesor\n");
		printf("3)RAM\n");
		printf("4)Coler\n");
		printf("5)Case\n");
		printf("If you wont exizt from program enter 6\n");
		do {
			scanf(" %d", &select);
			if (select < 1 || select>6) {
				printf("Enter the right walue:\n");
			}
		} while (select < 1 || select>6);

		switch (select)
		{
		case 1:
			/*
				removing quantiti of procesor from werhouse .
			*/
			break;
		case 2:
			//grafika
			break;
		case 3:
			//ram
			break;
		case 4:
			//hladnjak
			break;
		case 5:
			//kuciste
			break;
		case 6:
			//exizit 
			return;
			break;
		}

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
		//enter the GraphichCard
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

