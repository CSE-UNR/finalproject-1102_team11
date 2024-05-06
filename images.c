//James WIley
//5-5-24
//Purpose - FInal Project

#include<stdio.h>

#define FILE_ONE "test_image.txt"

#define ROWS 500
#define COLS 500
#define STR 35

void loadImg(FILE *img_fp, int rows, int cols, int image[][cols]);

int main(){
	
	char choice;
	int image[ROWS][COLS];
	FILE *img_fp;

		printf("Main Menu\n(L)oad an image\n(D)isplay the current image\n(E)dit the current image\ne(X)it\nWhat would you like to do? ");
		
		scanf(" %c", &choice);
		
		switch(choice){
			
			case 'l' :
			case 'L':
				
				loadImg(img_fp,  ROWS, COLS,  image);
				break;
			
			case 'd' :
			case 'D' :
				
				break;
				
			case 'e' :
			case 'E' :
				
				break;
				
			case 'x':
			case 'X':
				
				printf("entered x\n");
				
				break;
				
			default:
			
				printf("invalid entry");
				break;
		}
	
	return 0;
	
}

void loadImg(FILE *img_fp, int rows, int cols, int image[][cols]){
	
	char fileName[STR];
	int i = 0;
	
	printf("Enter the image name here: ");
	
	fgets(fileName, STR, stdin);
	
	if(fileName == "test_image" || fileName == "test_image.txt"){
		
		img_fp = fopen(FILE_ONE, "r");
	
		if(fopen == NULL){
		
			printf("Cannot open file\n");
			
		
		}
		else{
			
			while(fscanf(img_fp, "%d", *image) == 1){
					
				i++;
					
			}
			
		}
		
	}
	else{
		
		printf("file not found\n");
	}
	
}
