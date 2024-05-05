//Alysia Carr and Jalen Banks

//4/29/202



#include <stdio.h>

#define maxX 50  //500

#define maxY 50 //500

//Prototypes

void loadFile(char fileArray[maxX][maxY], char fileName[maxY]);
void printFile(char fileArray[maxX][maxY], int rows, int columns);
void rowColumnCount(char fileArray[maxX][maxY], int rows, int columns);
int getMenuChoice();
int getEditChoice();


int main(){


	int menuChoice, userEdit;

	char fileArray[maxX][maxY];
	char fileName[maxY];


	menuChoice = getMenuChoice();

	switch(menuChoice){
		case 1:
			printf("Enter the name of your file: ");
			//Read file name
			break;
		case 2:
			loadFile(fileArray, fileName);
			break;
		case 3:
			getEditChoice();
		case 0:
			printf("Goodbye. \n");
			break;
	}

	//userEdit = getEditChoice();


	//rowColumnCount(fileArray, rows, columns);


	return 0;
}



int getMenuChoice(){
	int menuChoice;
	printf("***ERINSTAGRAM***\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n");
	printf("\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &menuChoice);
	return menuChoice;
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





void dimPicture(){
//take each value in the array decrement them by 1
//assign new values to each of the spaces in the picture


}


void brightenPicture(){
//take each value and increment them by 1
//assign respective values to each of the spaces in the picture


}





void crop(){



}





//Current Work

void loadFile(char fileArray[maxX][maxY], char fileName[maxY]){

	FILE* fp;
	
	fp = fopen("test_image.txt", "r");
		if(fp == NULL){
			printf("Image could not be opened. \n");
		} 
 
		int i = 0;
		while(fgets(fileArray[i], 50, fp) != NULL){
			printf("%s", fileArray[i]);
			i++;
		}
		// for(int i = 0; i < rows; i++){

		// 	for(int j = 0; j < columns; j++){

		// 		fscanf(fp, "%c", &fileArray[i][j]);
		// 			switch(fileArray[i][j]){
		// 			case '1':
		// 				fileArray[i][j] == '.';
		// 				break;
		// 			case '2':
		// 				fileArray[i][j] == 'o';
		// 				break;
		// 			case '3':
		// 				fileArray[i][j] == 'O';
		// 				break;
		// 			case '4':
		// 				fileArray[i][j] == '0';
		// 				break;
		// 			default:
		// 				fileArray[i][j] == ' ';
		// 				break;
		// 			}
		// 	}

		// }
	fclose(fp);
}



void printFile(char fileArray[maxX][maxY], int rows, int columns){

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			// switch(fileArray[i][j]){
			// 	case '1':
			// 		fileArray[i][j] == '.';
			// 		break;
			// 	case '2':
			// 		fileArray[i][j] == 'o';
			// 		break;
			// 	case '3':
			// 		fileArray[i][j] == 'O';
			// 		break;
			// 	case '4':
			// 		fileArray[i][j] == '0';
			// 		break;
			// 	default:
			// 		fileArray[i][j] == ' ';
			// 		break;
			// }
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
	// for(int i = 0; i < rows; i++){
	// 		for(int j = 0; j < columns; j++){
	// 			if(fileArray[i][j] == '\n'){
	// 				row_count++;
	// 			}
	// 		}
	// 		column_count = columns;
	// 	}

	printf("\n");
	printf("Row count: %d", row_count + 1);
	printf("Column count: %d", column_count);

}
