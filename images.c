//Alysia Carr and Jalen Banks

//4/29/202



#include <stdio.h>


#define MAX_NUM_LINES 500
#define MAX_LINE_LENGTH 500
#define MAX_FILE_NAME_LENGTH 500

#define maxY 50 //500
#define maxX 50  //500
//I think we should change this name
//Hard to differentiate from an actual string, same as string data type, like our file name dec.
#define STRING 50

//Prototypes
int strLen(char str[MAX_LINE_LENGTH]);
int loadFile(char image[MAX_NUM_LINES][MAX_LINE_LENGTH]);
void printImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength);
void convertImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength);
void dimImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength);
int getMenuChoice();
int getEditChoice();
void cropImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength);
void brightenImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength);
void saveImage(FILE *fp);

int main(){
	int menuChoice, editChoice, row, column, rowResult;

	char image[MAX_NUM_LINES][MAX_LINE_LENGTH];

	int numLines;
	int lineLength;

	do{
		menuChoice = getMenuChoice();

		switch(menuChoice){
			case 1:
				numLines = loadFile(image);
				lineLength = strLen(image[0]);
				break;
			case 2:
				convertImage(image, numLines, lineLength);
				printImage(image, numLines, lineLength);
				break;
			case 3:
				editChoice = getEditChoice();

				switch(editChoice){
					case 1:
						cropImage( image, numLines, lineLength);
						printImage(image, numLines, lineLength); 
						//saveImage();
						break;
					case 2:
						dimImage(image, numLines, lineLength); 
						printImage(image, numLines, lineLength);
						//saevImage(); 
						break;
					case 3:
						brightenImage(image, numLines, lineLength);
						printImage(image, numLines, lineLength);
						//saveImage();
						break;
					case 0:
						//exit
						break;
				}
		}

		
	} while(menuChoice != 0);

	printf("Goodbye!");
	printf("\n");

	return 0;
}

void cropImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength){
    int columnLeft = 0, columnRight = 0, rowTop= 0, rowBottom = 0;
    printf("The image you want to crop is %d x %d\n", numLines, lineLength);
    printf("The row and column values start in the upper lefthand corner.\n");
    printf("Which column do you want to be the new left side? ");
    while(columnLeft < lineLength){
    scanf("%d", image[columnLeft]);
    	if(image[][columnLeft] >= 1 && image[][columnLeft] <= lineLength){
    		columnLeft++;
   	 } else{
   		printf("Invalid column value. Choose again: ");
    		scanf("%d", &image[][columnLeft]);
   	 }
    }
    
    printf("Which column do you want to be the new right side? ");
    while(columnRight < image[][columnLeft]){
    	scanf("%d", image[][columnRight]);
    		if(image[][columnRight] <= 1 && image[][columnRight] <= image[][columnLeft]){
    			columnRight++;
   	 } else{
   		printf("Invalid column value. Choose again: ");
    		scanf("%d", &image[][columnRight]);
   	 }
    }
    
    printf("Which row do you want to be the new top? ");
    while(rowTop < numLines){
    	scanf("%d", image[rowTop][]);
    		if(image[rowTop][] >= 1 && image[rowTop][] <= numLines){
    			rowTop++;
   	 } else{
   		printf("Invalid row value. Choose again: ");
    		scanf("%d", &image[rowTop][]);
   	 }
    }
    
    printf("Which row do you want to be the new bottom? ");
    while(rowBottom < image[rowTop][]){
    	scanf("%d", image[rowBottom][]);
    		if(image[rowBottom][] >= 1 && image[rowBottom][] <= image[rowTop][]){
    			rowBottom++;
   	 } else{
   		printf("Invalid row value. Choose again: ");
    		scanf("%d", &image[rowBottom][]);
   	 }
    }
    for(int i = 0; i < size; i++){
    	for(int j = 0; j < size; j++){
    		printf("%c", image[rowBottom][]);
    		
    	
    	}
    }
}

void printImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength){
	printf("\n");
	for(int i=0; i< numLines; i++){
		for(int j=0; j<lineLength; j++){
			printf("%c", image[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void dimImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength){
	for(int i=0; i<numLines; i++){
		for(int j=0; j<lineLength; j++){
			switch (image[i][j]){
				case ' ':
					break;
				case '.':
					image[i][j] = ' ';
					break;
				case 'o':
					image[i][j] = '.';
					break;
				case 'O':
					image[i][j] = 'o';
					break;
				case '0':
					image[i][j] = 'O';
					break;
				default:
					break;
			}
		}
	}
}

void brightenImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength){
	for(int i=0; i<numLines; i++){
		for(int j=0; j<lineLength; j++){
			switch (image[i][j]){
				case '0':
					break;
				case ' ':
					image[i][j] = '.';
					break;
				case '.':
					image[i][j] = 'o';
					break;
				case 'o':
					image[i][j] = 'O';
					break;
				case 'O':
					image[i][j] = '0';
					break;
				default:
					break;
			}
		}
	}
}

void convertImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength){
	for(int i=0; i<numLines; i++){
		for(int j=0; j<lineLength; j++){
			switch (image[i][j]){
				case '0':
					image[i][j] = ' ';
					break;
				case '1':
					image[i][j] = '.';
					break;
				case '2':
					image[i][j] = 'o';
					break;
				case '3':
					image[i][j] = 'O';
					break;
				case '4':
					image[i][j] = '0';
					break;
				default:
					break;
			}
		}
	}
}

int loadFile(char image[MAX_NUM_LINES][MAX_LINE_LENGTH]){
    
	char fileName[MAX_FILE_NAME_LENGTH];

    FILE* fp;
	
	printf("What is the name of the image file? ");

	scanf("%s", fileName);

    fp = fopen(fileName, "r");

   	if(fp == NULL){
   		 printf("Could not find an image with that file name. \n");
		return -1;
   	}

	int i = 0;

	while(fgets(image[i], MAX_LINE_LENGTH, fp) != NULL){
		//printf("%s", image[i]);//TODO: Delete
		i++;
	}

	fclose(fp);

	printf("Image successfully loaded!\n");

	return i;
}

void cpyStr(char source[], char destination[]){
	int i=0;
	while(source[i] != '\0'){
		destination[i] = source[i];
		i++;
	}

	destination[i] = '\0';
}

int strLen(char str[]){

	int i = 0;

	while( (str[i] != '\0') && (str[i] != '\n')){
		i++;
	}

	if(str[i] == '\n'){
		i--;
	}

	return i;
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
    printf("0: Return to main menu\n");
    printf("\n");
    printf("Choose from one of the options above: ");
    scanf("%d", &userEdit);
    return userEdit;
}

void saveImage(FILE *fp){
    char fileName[maxX+1], saveChoice;
    printf("Would you like to save image? (y/n): ");
    scanf(" %c",&saveChoice);
    if(saveChoice == 'y' || saveChoice == 'Y'){
   	 printf("What do you want to name the image file? (inlcude the extension): ");
   	 scanf("%s", fileName);
   	 //fgets(fileName, STRING, stdin);
   	 for (int i = 0; fileName[i] != '\0'; i++){
   		 if(fileName[i] == '\n'){
   			 fileName[i] = '\0';
   		 }
   	 }
   	 fp = fopen(fileName, "w");
   	 if (fp == NULL){
   		 printf("Can't open file \n");
   	 }
   	 else{
   		 //fgets(fileName, , fp);
    
   		 //for(int ){
   		 //}
   		 //for(int ){
   		 //}
   	 
   	 //fclose(fileName);
   	 }
    }
}
