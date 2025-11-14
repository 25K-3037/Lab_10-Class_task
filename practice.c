#include <stdio.h>
#include <string.h>
int main(){
	
	char word[4][10] = {"Apple", "Grapes", "Aloo", "Machli"};
	int i,j;
	strcpy(word[2],"lychee");
	for (i=0;i<4;i++){
		
		puts(word[i]);
		printf("%d\n", strlen(word[i]));
		
	//	for (j=0;word[i][j]!='\0' ; j++){
	//		printf("%c\n",word[i][j]);
		
	}

	
	return 0;
	
}
