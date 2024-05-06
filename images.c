//James Wiley
//5-5-24
//Purpose - FInal Project

#include<stdio.h>

#define ROWS 500
#define COLS 500
#define STR 35

void loadImg(FILE *img_fp, int rows, int cols, int image[][cols]);

int main(){
	
	char choice;
	int image[ROWS][COLS];
	FILE *img_fp;

		printf("Main Menu\n(L)oad an image\n(D)isplay the current image\n(E)dit the current image\ne(X)it\nWhat would you like to do?: ");
		
		scanf(" %c", &choice);
		
		switch(choice){
			
			case 'l':
			case 'L':
				
				loadImg(img_fp, ROWS, COLS, image);
				
				break;
			
			case 'd':
			case 'D':
				
				break;
				
			case 'e':
			case 'E':
				
				break;
				
			case 'x':
			case 'X':
				
				printf("entered x\n");
				
				break;
				
			default:
			
				printf("invalid entry");
				//wanna see if i can have it print the menu again instead of
				//just ending the program
				break;
		}
	
	return 0;
	
}

void loadImg(FILE *img_fp, int rows, int cols, int image[][cols]){
	
	char fileName[STR], trash;
	int i = 0;
	
	printf("Enter the image name here: ");

	scanf(" %s", fileName);
	scanf("%c", &trash);
		
	img_fp = fopen(fileName, "r");

	if(fopen == NULL){
	
		printf("Cannot open file\n");
	
	}
	else{
		
		while(fscanf(img_fp, "%d", *image) == 1){
				
			i++;
				
		}
		
	}
	
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			
			printf("%d", image[r][c]);
		}
	}
}
