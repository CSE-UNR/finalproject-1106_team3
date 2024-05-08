//Alysia Carr and Jalen Banks

//4/29/202



#include <stdio.h>


#define MAX_NUM_LINES 500
#define MAX_LINE_LENGTH 500
#define MAX_FILE_NAME_LENGTH 500
#define NAME 50

//Prototypes
int strLen(char str[MAX_LINE_LENGTH]);
int loadFile(char image[MAX_NUM_LINES][MAX_LINE_LENGTH]);
void printImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength);
void convertImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength);
void dimImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength);

int getMenuChoice();
int getEditChoice();
void cropImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int* numLines, int* lineLength);
void brightenImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength);
void saveImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH],int numLines, int lineLength);

int main(){
	int menuChoice, editChoice, rows, columns, rowResult;
	char image[MAX_NUM_LINES][MAX_LINE_LENGTH];
	char fileName[NAME];
	int numLines;
	int lineLength;

	
	do{
		menuChoice = getMenuChoice();

		switch(menuChoice){
			case 1:
				numLines = loadFile(image);
				lineLength = strLen(image[0]);
                convertImage(image, numLines, lineLength);
				break;
			case 2:
                if(numLines != 0){
                    printImage(image, numLines, lineLength);
                }else{
                    printf("Sorry, there is no image to display. \n");
                }
				break;
			case 3:
                if(numLines != 0){
                    editChoice = getEditChoice();
                    switch(editChoice){
                        case 1:
                            cropImage(image, &numLines, &lineLength);
                            break;
                        case 2:
                            dimImage(image, numLines, lineLength); 
                            printImage(image, numLines, lineLength); 
                            saveImage(image, numLines, lineLength);
                            break;
                        case 3:
                            brightenImage(image, numLines, lineLength);
                            printImage(image, numLines, lineLength);
                            saveImage(image,numLines, lineLength);
                            break;
                        case 0:
                            //exit
                            break;
                        default:
                            printf("Invalid option, please try again. \n");
                            break;
                    }
                }else{
                    printf("Sorry, no image to edit. \n");
                }
		}
	} while(menuChoice != 0);

	printf("Goodbye!");
	printf("\n");

	return 0;
}

void cropImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int* numLines, int* lineLength){
    int columnLeft = 0, columnRight = 0, rowTop= 0, rowBottom = 0;
    printImage(image, *numLines, *lineLength);

    printf("The image you want to crop is %d x %d. \n", *numLines, *lineLength);

    printf("The row and column values start in the upper lefthand corner.\n\n");

    printf("Which column do you want to be the new left side? ");

    scanf("%d", &columnLeft);

    while(columnLeft < 0 || columnLeft > *lineLength){
        printf("Invalid column left value. Choose again: ");
        scanf("%d", &columnLeft);
    }

    printf("\nWhich column do you want to be the new right side? ");

    scanf("%d", &columnRight);

    while(columnRight <= columnLeft || columnRight > *lineLength){
        printf("Invalid column right value. Choose again: ");
        scanf("%d", &columnRight);
    }

    printf("\nWhich row do you want to be the new top? ");

    scanf("%d", &rowTop);

    while(rowTop < 0 || rowTop > *numLines){
        printf("Invalid row top value. Choose again: ");
        scanf("%d", &rowTop);
    }

    printf("\nWhich row do you want to be the new bottom? ");

    scanf("%d", &rowBottom);

    while(rowBottom <= rowTop || rowBottom > *numLines){
        printf("Invalid row bottom value. Choose again: ");
        scanf("%d", &rowBottom);
    }

    *numLines = rowBottom - rowTop;
    *lineLength = columnRight - columnLeft;

    printImage(image, *numLines, *lineLength);
    saveImage(image, *numLines, *lineLength);
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
		i++;
	}

	fclose(fp);

	printf("Image successfully loaded! \n");

	return i;
}

void cpyStr(char source[], char destination[]){
	int i = 0;

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

    // if(str[i] = '\n'){
    //     i--;
    // }

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

void saveImage(char image[MAX_NUM_LINES][MAX_LINE_LENGTH], int numLines, int lineLength){
    char saveChoice;
    char fileName[MAX_LINE_LENGTH];
        
    printf("Would you like to save image? (y/n): ");
    scanf(" %c",&saveChoice);

    if(saveChoice == 'y' || saveChoice == 'Y'){

        printf("What do you want to name the image file? (inlcude the extension): ");
        scanf("%s", fileName);

        FILE* fp;

        fp = fopen(fileName, "w");

        if(fp == NULL){
            printf("Cannot open file. \n");
        }

	    for(int i=0; i< numLines; i++){
            for(int j=0; j<lineLength; j++){
                fprintf(fp, "%c", image[i][j]);
            }
		    fprintf(fp, "\n");
	    }

        printf("\n");

        fclose(fp);
    }
}
