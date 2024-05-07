//Alysia Carr and Jalen Banks

//4/29/202



#include <stdio.h>

#define maxX 50  //500
#define maxY 50 //500
#define MAX_FILE_NAME_LENGTH 50
//I think we should change this name
//Hard to differentiate from an actual string, same as string data type, like our file name dec.
#define STRING 50

//Prototypes

void loadFile(char fileArray[maxX][maxY], int *row_count);
void printFile(char fileArray[maxX][maxY], int rows, int columns, FILE* fp);
void rowColumnCount(char fileArray[maxX][maxY], int rows, int columns);
int getMenuChoice();
int getEditChoice();
void cropImage( int numbers, int size, int array[]);
void dimImage(int row, int column, int fileArray[][column], FILE* fp);
void brightenImage(int row, int column, int fileArray[][column], FILE* fp);
void saveImage(FILE *fp);

int main(){

    int menuChoice, editChoice, row, column, rowResult;

    char fileArray[maxX][maxY];

    do{
   	 menuChoice = getMenuChoice();
   	 
    
   	 switch(menuChoice){
   		 case 1:
   			 //printFile(
   			 //printf("Enter the name of your file: ");
   			 //Read file name
   			 break;
   		 case 2:
   			 loadFile(fileArray, &rowResult);
   			 break;
   		 case 3:
   			 editChoice = getEditChoice();
   			 switch(editChoice){
   				 case 1:
   				 	//cropImage( int numbers, int size, int array[]);
   					 break;
   				 case 2:
   				 	//dimImage(row, column, fileArray, fp);
   				 	//saveImage(fp);
   					 break;
   				 case 3:
   			 
   					 break;
   				 case 0:
   					 //exit
   					 break;
   				 }
   	 }



   	 //rowColumnCount(fileArray, rows, columns);
    } while(menuChoice != 0);
    printf("Goodbye!");
    printf("\n");

    return 0;
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





// void dimImage(int row, int column, int fileArray[][column], FILE* fp){
// 	int dim;
//     for(int i = 0; i < row; i++){
//    	 for(int j = 0; j < column; j++){    
//    		 switch(dim){
//    			 case 0:
//    				 fprintf(fp, " ");
//    				 break;
//    			 case 1:
//    				 fprintf(fp, ".");
//    				 break;
//    			 case 2:
//    				 fprintf(fp, "o");
//    				 break;
//    			 case 3:
//    				 fprintf(fp, "O");
//    				 break;
//    			 }
//    		 }
//    	 }
// }    



// void brightenImage(int row, int column, int fileArray[][column], FILE* fp){
// 	int bright;
//     for(int i = 0; i < row; i++){
//    	 for(int j = 0; j < column; j++){    
//    		 switch(bright){
//    			 case 0:
//    				 fprintf(fp, ".");
//    				 break;
//    			 case 1:
//    				 fprintf(fp, "o");
//    				 break;
//    			 case 2:
//    				 fprintf(fp, "O");
//    				 break;
//    			 case 3:
//    				 fprintf(fp, "0");
//    				 break;
//    			 }
//    		 }
//    	 }
// }


// void cropImage( int numbers, int size, int array[]){
//     int tempCount = 0;
//     printf("The image you want to crop is # x #\n");
//     printf("The row and column values start in the upper lefthand corner.\n");
//     printf("Which column do you want to be the new left side? ");
//     while(tempCount < size){
//     	scanf("%d", array[tempCount]);
//     	if(array[tempCount] <= 0 && array[tempCount] >= 50){
//     		tempCount++;
//     	}
//     	else{
//     		printf("Invalid column value. Chose a value between 1 and 50: ");
//     		scanf("%d", &array[tempCount]);
//     	}
//     }
// }
    







//Current Work

void loadFile(char fileArray[maxX][maxY], int *row_count){
    
    int row = 0;
    int column = 0;
	char fileName[MAX_FILE_NAME_LENGTH];

    FILE* fp;
	
	printf("What is the name of the image file? ");
	scanf("%s", fileName);

	//printf("%s \n", fileName);

    fp = fopen(fileName, "r");

   	if(fp == NULL){
   		 printf("Could not find an image with that file name. \n");
		return;
   	}

	// int i = 0;

	// while(fgets(fileArray[i], maxY, fp) != NULL){
	// 	printf("%s", fileArray[i]);
	// 	i++;
	// 	row++;
	// }
	
	// fclose(fp);

	// for ( i = 0; i < row; i++){
	// 	for(int j =0; j < maxY; j++){
	
   	// 		switch(fileArray[i][j]){
   	//      		case '1':
   	//      			fileArray[i][j] = '.';
   	//      			break;
   	//      		case '2':
   	//      			fileArray[i][j] = 'o';
   	//      			break;
   	//      		case '3':
   	//      			fileArray[i][j] = 'O';
   	// 				break;
   	// 			case '4':
   	// 				fileArray[i][j] = '0';
   	//      			break;
   	// 			default:
   	//      			fileArray[i][j] = ' ';
   	//      			break;
   	// 		}  
	// 	}
	// }

	// printf("\n");
   	// printf("Rows: %d \n", row);
   	// printf("Columns: %d", column);

	// *row_count = row;

   	//  for(int i = 0; i < row; i++){
   	// 	 for(int j = 0; j < maxY; j++){
   	//      	 printf("%c", fileArray[i][j]);
   	//       }
   	//   }
	// printf("\n");
}


//Figure out later
void printFile(char fileArray[maxX][maxY], int rows, int columns, FILE* fp){

    for(int i = 0; i < rows; i++){
   	 for(int j = 0; j < columns; j++){
   		 if(fp == stdout){
   		  switch(fileArray[i][j]){
   		      case '1':
   		     	 fileArray[i][j] == '.';
   		     	 break;
   		      case '2':
   		     	 fileArray[i][j] == 'o';
   		     	 break;
   		      case '3':
   		     	 fileArray[i][j] == 'O';
   		     	 break;
   		      case '4':
   		     	 fileArray[i][j] == '0';
   		     	 break;
   		      default:
   		     	 fileArray[i][j] == ' ';
   		     	 break;
   		  }
   			 fprintf(fp, "%c", fileArray[i][j]);
   		 }
   		 else{
   			 fprintf(fp, "%d", fileArray[i][j]);
   		 }
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
    //    	 for(int j = 0; j < columns; j++){
    //    		 if(fileArray[i][j] == '\n'){
    //    			 row_count++;
    //    		 }
    //    	 }
    //    	 column_count = columns;
    //     }

    printf("\n");
    printf("Row count: %d", row_count + 1);
    printf("Column count: %d", column_count);

}
