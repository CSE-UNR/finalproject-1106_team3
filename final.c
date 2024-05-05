//Alysia Carr and Jalen Banks

//4/29/202



#include <stdio.h>

#define maxX 14

#define maxY 21

//Prototypes

void readFile(int userChoice, char fileArray[maxX][maxY], int rows, int columns);

void printFile(char fileArray[maxX][maxY], int rows, int columns);

void rowColumnCount(char fileArray[maxX][maxY], int rows, int columns);
int getMenuChoice();
int getEditChoice();


int main(){


	int menu, edit;
	menu = getMenuChoice();
	edit = getEditChoice();

	char fileArray[maxX][maxY];

	int rows = 14;

	int columns = 21;

	

	

	printf("Enter your choice: \n");

	scanf("%d", &userChoice);

	printf("\n");

	

	readFile(userChoice, fileArray, rows, columns);

	rowColumnCount(fileArray, rows, columns);



}



int getMenuChoice(){
	int userMenu;
	printf("***ERINSTAGRAM***\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n");
	printf("\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &userMenu);
	return userMenu;
}



int getEditChoice(){
	int userEdit;
	printf("**EDITING**\n");
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Exit\n");
	printf("\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &userEdit);
	return userEdit;
}





void saveImage(){



}





void editFunction(){



}





void dimBrighten(){



}





void crop(){



}





//Current Work

void readFile(int userChoice, char fileArray[maxX][maxY], int rows, int columns){

	FILE* fp;

	

	if(userChoice == 1){

	fp = fopen("test_image.txt", "r");

		if(fp == NULL){

			printf("Image could not be opened \n");

		} 

		for(int i = 0; i < rows; i++){

			for(int j = 0; j < columns; j++){

				fscanf(fp, "%c", &fileArray[i][j]);

			}

		}

	}

	printFile(fileArray, rows, columns);

	rowColumnCount(fileArray, rows, columns); 

	fclose(fp);

}



void printFile(char fileArray[maxX][maxY], int rows, int columns){

	for(int i = 0; i < rows; i++){

		for(int j = 0; j < columns; j++){

			printf("%c", fileArray[i][j]);

		}

	}

}



void rowColumnCount(char fileArray[maxX][maxY], int rows, int columns){

	//iterate over each spot in the picture

	//for each value in the x direction we want to column++

	//for each spot in the y direction we want to row++

	int row_count = 0;

	int column_count = 0;

	for(int i = 0; i < rows; i++){

			for(int j = 0; j < columns; j++){

				if(fileArray[i][j] == '\n'){

					row_count++;

				}

			}

			column_count = columns;

		}

	printf("\n");

	printf("Row count: %d", row_count);

	printf("Column count: %d", column_count);

}



