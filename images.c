//James Wiley
//5-5-24
//Purpose - FInal Project

#include<stdio.h>

#define ROWS 30
#define COLS 30
#define STR 35

void loadImg(FILE *img_fp, int rows, int cols, int source[][cols]);
void displayImg(int rows, int cols, char image[][cols]);
void translate(int rows, int cols, int source[][cols], char image[][cols]);

int editMenu(int rows, int cols, int source[][cols], char image[][cols]);
void dimImg(int rows, int cols, int source[][cols]);
void brightenImg(int rows, int cols, int source[][cols]);
void cropImg(int rows, int cols, int source[][cols]);
void rotate(int rows, int cols, int source[][cols], char image[][cols]);

int main(){
	
	char choice, image[ROWS][COLS]  = {' '};
	int source[ROWS][COLS], rows, cols;
	FILE *img_fp;
	
	do{
			printf("	Main Menu\n(L)oad an image\n(D)isplay the current image\n(E)dit the current image\ne(X)it\nWhat would you like to do?: ");
			
			scanf(" %c", &choice);
			
			switch(choice){
				
				case 'l':
				case 'L':
					
					loadImg(img_fp, ROWS, COLS, source);
					
					break;
				
				case 'd':
				case 'D':
					
					translate(ROWS, COLS, source, image);
					displayImg(ROWS, COLS, image);
					
					break;
					
				case 'e':
				case 'E':
					
					editMenu(ROWS, COLS, source, image);
					
					break;
					
				case 'x':
				case 'X':
					
					return 0;
					
					break;
					
				default:
				
					printf("invalid entry\n");
					//wanna see if i can have it print the menu again instead of
					//just ending the program
					break;
			}
	
	}while(choice != 'X' || choice !='x');
	return 0;
	
}

void loadImg(FILE *img_fp, int rows, int cols, int source[][cols]){
	
	char fileName[STR], trash;
	int i = 0, placeholder;
	
	printf("Enter the image name here: ");

	scanf(" %s", fileName);
	scanf("%c", &trash);
		
	img_fp = fopen(fileName, "r");

	if(fopen == NULL){
	
		printf("Cannot open file\n");
	
	}
	else{
		
		for(int r = 0; r < rows; r++){
		
			for(int c = 0; c < cols; c++){
			
				fscanf(img_fp, " %d", &source[r][c]);
								
				if(source[r][c] = ' '){
					
					
					r++;
					
				}
				
			}
			
		}
		
		printf("Image Loaded!\n");
		fclose(img_fp);
		
	}
	
}

void displayImg(int rows, int cols, char image[][cols]){
	
	for(int r = 0; r < ROWS; r++){
		for(int c = 0; c < COLS - 1; c++){
							
			printf("%c", image[r][c]);
		}
	}
					
	printf("\n");
}
void translate(int rows, int cols, int source[][cols], char image[][cols]){
	
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			
			if(source[r][c] == 0){
				
				image[r][c] = ' ';
			}
			else if(source[r][c] == 1){
				
				image[r][c] = '.';
			}
			else if(source[r][c] == 2){
				
				image[r][c] = 'o';
			}
			else if(source[r][c] == 3){
				
				image[r][c] = 'O';
			}
			else if(source[r][c] == 4){
				
				image[r][c] = '0';
			}
			else{
				
				image[r][c] = ' ';
				
			}
			
		}
	}
	
}

int editMenu(int rows, int cols, int source[][cols], char image[][cols]){
	
	char Choice;
	int edit[rows][cols];
	
		printf("	Image Editor\n(C)rop\n(D)im\n(B)righten\n(R)otate\ne(X)it\nHow would you like to edit the image? ");
		
		scanf(" %c", &Choice);
		
		switch(Choice){
			
			case 'c':
			case 'C':
				
				//crop
				cropImg(ROWS, COLS, source);
				translate(ROWS, COLS, source, image);	
				displayImg(ROWS, COLS, image);		
				break;
				
			case 'd':
			case 'D':
				
				//dim
				dimImg(ROWS,COLS, source);
				translate(ROWS, COLS, source, image);
				displayImg(ROWS, COLS, image);
				
				break;
			
			case 'b':
			case 'B':
				
				//brighten
				//idc if i can make these 1 function i aint doin allat
				brightenImg(ROWS, COLS, source);
				translate(ROWS, COLS, source, image);
				displayImg(ROWS, COLS, image);
				
				break; 
			
			case 'r':
			case 'R':
				
				//rotate if i can get to it
				rotate(ROWS, COLS, source, image);
				break;
				
			case 'x':
			case 'X':
				
				break;
			
			default:
				
				printf("invalid choice\n");
				break;
				
		}
	
	return 0; 
}

void dimImg(int rows, int cols, int source[][cols]){
	
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			
			source[r][c]--;
			
		}
	}
}

void brightenImg(int rows, int cols, int source[][cols]){
	
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			
			source[r][c]++;
			
		}
	}
}

void cropImg(int rows, int cols, int source[][cols]){
	
	int r1, r2, c1, c2, placeholder;
	
	printf("starting row: ");
	scanf(" %d", &r1);
	printf("starting column: ");
	scanf(" %d", &c1);
	printf("ending row: ");
	scanf(" %d", &r2);
	printf("ending column: ");
	scanf(" %d", &c2);
	
	for(int r = r1; r < r2; r++){
		for(int c = c1; c < c2; c++){
			source[r][c] = placeholder;
		}
	}
}

void rotate(int rows, int cols, int source[][cols], char image[][cols]){
	
	int rotation[rows][cols];
	
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			rotation[r][c] == source[c][r];
		}
	}
	
	translate(ROWS, COLS, rotation, image );
	displayImg(ROWS, COLS, image);
}
