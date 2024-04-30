//Alysia Carr and Jalen Banks
//4/29/202

#include <stdio.h>
#define maxY 50
#define maxX 50
//Prototypes
void readFile(FILE* fp, int userChoice);




int main(){
	FILE* fp;
	int userChoice;
	int userEdit; //For edit menu
	
	printf("Enter your choice: \n");
	scanf("%d", userChoice);
	readFile(fp, userChoice);

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
void readFile(FILE* fp,int userChoice){
	if(userChoice == 1){
	fp = fopen("test_image.txt", "r");
		if(fp == NULL){
			printf("Image could not be opened \n");
		} 
		for(int i = 0; i < maxX; i++){
			for(int j = 0; j < maxY; j++){
			
			}
		{
	} 
	fclose(fp);
}
