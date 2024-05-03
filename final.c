//Alysia Carr and Jalen Banks
//4/29/202

#include <stdio.h>
#define maxX 12
#define maxY 21
//Prototypes
void readFile(int userChoice, char fileArray[maxX][maxY]);
void printFile(char fileArray[maxX][maxY]);
int getMenuChoice();
int getEditChoice();


int main(){

	int menuChoice, editChoice;
	char fileArray[maxX][maxY];
	menuChoice = getMenuChoice();
	editChoice = getEditChoice();
	printf("Enter your choice: \n");
	scanf("%d", &userChoice);
	readFile(userChoice, fileArray);

}

int getMenuChoice(){
		int userInput;
		printf("***ERINSTAGRAM***\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit\n");
		printf("\n");
		printf("Choose from one of the options above: ");
		scanf("%d", &userInput);
		return userInput;
	}
	
int getEditChoice(){
	int userEdit;
	printf("**EDITING**\n");
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("4: Rotate image\n");
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
void readFile(int userChoice, char fileArray[maxX][maxY]){
	FILE* fp;
	
	if(userChoice == 1){
	fp = fopen("test_image.txt", "r");
		if(fp == NULL){
			printf("Image could not be opened \n");
		} 
		for(int i = 0; i < maxX; i++){
			for(int j = 0; j < maxY; j++){
				fscanf(fp, "%c", &fileArray[i][j]);
				switch(fileArray[i][j]){
					case '1':
						fileArray[i][j] = '1';
						break;
					case '4':
						fileArray[i][j] = '4';
						break;
					default:
						fileArray[i][j] = '0';
						break;	
				}
			}
		}
	} 
	printFile(fileArray);
	fclose(fp);
}

void printFile(char fileArray[maxX][maxY]){
	for(int i = 0; i < maxX; i++){
		for(int j = 0; j < maxY; j++){
			printf("%c", fileArray[i][j]);
		}
	printf("\n");
	}
}

