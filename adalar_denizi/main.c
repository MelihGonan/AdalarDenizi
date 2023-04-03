#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Harita global degisken olarak tanimlandi.
int harita[6][6]={{1,1,0,0,1,1},
				  {1,0,0,0,1,1},
				  {0,0,1,1,1,0},
				  {0,0,1,0,0,0},
				  {0,0,0,0,1,1},
				  {0,1,0,1,0,0} };

// Bulunan ada isaretlenir.
void degerdegis(int i,int j){
	
	harita[i][j]=2;
	
	if(harita[i+1][j]==1)
		degerdegis((i+1),j);
	
	if(harita[i][j+1]==1)
		degerdegis(i,(j+1));
		
	if(j>=0 && harita[i][j-1]==1)
		degerdegis(i,(j-1));
		
	if(i>=0 && harita[i-1][j]==1)
		degerdegis((i-1),j);	
}

int main(int argc, char *argv[]) {
	
	// Degiskenler tanimlandi.
	int adasayisi=0;
	int i,j;
	
	// Harita ekrana yazildi.
	printf("Harita:\n");
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			
			printf("%d ",harita[i][j]);
		}	printf("\n");
	}
	
	// Ada sayisi hesaplandi.
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			
			if(harita[i][j]==1){
				
				degerdegis(i,j);
				adasayisi++;
			}
		}	
	}

	printf("\nAda sayisi : %d",adasayisi);
	
	return 0;
}
