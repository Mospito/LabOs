#include <stdio.h>
void Bubble(void);

 int main(void) {
 int selection;
 printf("Please select one of these options\n\n");
 printf("1) bubble sort\n");
 printf("2) Quit\n");
 scanf("%d",&selection);
 switch(selection) {
 case 1 : Bubble(); break;
 case 2 : break;


default : printf("Unknow option\n"); break;
}
 printf("\n...Bye...\n");


return(0);
}
 void Bubble(void) {
 int input[10];
 int temp, i, j, k,n;



printf("Please enter #Number of loop: ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Please enter #%d: ",i+1);
scanf("%d",&input[i]);
}

for(i=0;i<n-1;i++){
for(j=i;j<n;j++){
if(input[j] < input[i]){
temp = input[i];
input[i] = input[j];
input[j] = temp;

}
}
}

printf("The sorted list is: ");
for(k=0;k<n;k++){
printf("%d " ,input[k]);
}
printf("\n");
}

