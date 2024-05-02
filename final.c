//Alysia Carr and Jalen Banks
//4/29/202

#include <stdio.h>
#define maxX 12
#define maxY 21
//Prototypes
void readFile(int userChoice, char fileArray[maxX][maxY]);
void printFile(char fileArray[maxX][maxY]);


int main(){

	int userChoice;
	int userEdit; //For edit menu
	char fileArray[maxX][maxY];
	
	printf("Enter your choice: \n");
	scanf("%d", &userChoice);
	readFile(userChoice, fileArray);

}

void getMenuChoice(){

}


void editMenuChoice(){

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

