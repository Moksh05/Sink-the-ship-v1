#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct coord{
    int x;
    int y;
}cood;

void restart(void);
void print(int arr[4][4]);
char printgui(char arr[4][4]);
int backend(int arr[4][4],int *x);
char frontend(char arr[4][4]);
void battle(struct coord cood,int arr[4][4],char ary[4][4],int *x ,int *y);

int main(){
    int comp[4][4],no_ship=0;
    char gui[4][4],r,p;
    printf("\t\t\t\t------ Sink The Ship ------ \n\n\t\t\t\t\t  WELCOME! \n\n\n To the game press Enter key to start ");

    do{
        scanf("%c",&r);         // to make enter as an input to continue
    }while(r!='\n');

    printf("\n\n\n");

    comp[4][4]=backend(comp,&no_ship);   // it is working till here - creating an array for ship rep by 1
    int chance = (no_ship/2)+1;
    gui[4][4]=frontend(gui);        // it is working till here - creating an array of * and everything

    while((no_ship!=0)&&(chance!=0)){
    printgui(gui);
    printf("Number of ships to be sunken : %d\n",no_ship);
    printf("Number of attempts left : %d\n",chance);
    battle(cood,comp,gui,&no_ship,&chance);
    }

    if(no_ship==0){
        printgui(gui);
        printf("\n\n\nWINNER!!!!!!!!!");
    }
    else{
        printgui(gui);
        printf("\n\n\nYOU LOSE !!!!!!!!!!!!");
    }
    
    printf("\n\n\nDo you want to play again [Y/N] : ");
    scanf("%c",&p);
    if(p=='Y'){
        main();
    }
    else{  
        printf("\n\n\nThank you for playing");
    }
    
return 0;
}

//to print the matrix of ship for personal chck
void print(int arr[4][4]){
    for (int i = 0; i < 4; i++)
    {
        printf("[");
        for (int j = 0; j < 4; j++)
        {
            printf("%d , ",arr[i][j]);
        }
        printf("]\n");
    }
    
}

//to print the array of star to show to user
char printgui(char arr[4][4]){
    printf("        ");
    for (int k = 1; k < 5; k++)
    {
        printf("  %d  ",k);
    }    
    printf("\n\n\n");
    for (int i = 0; i < 4; i++)
    {  
        printf("    %d   ", i+1);
        for (int j = 0; j <4; j++)
        {
            
            printf("  %c  ",arr[i][j]);
        }
        printf("\n\n");
    }
    return arr[4][4];
    
}

// to make matrix of ship and empty space
int backend(int arr[4][4],int *x){
    srand((unsigned)time(NULL));
    do{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {   
            
            arr[i][j]= rand()%2 ;
            if(arr[i][j]==1){
                *x+=1;
            }
        }
        
    }
    }while((*x<7)||(*x>13));
    return arr[4][4];
}

// to make the * matrix
char frontend(char arr[4][4]){
    for (int i = 0; i <4; i++)
    {
        for (int j = 0; j <4; j++)
        {
            arr[i][j]='*';
        }
        
    }
}

//main logic
void battle(struct coord cood,int arr[4][4],char ary[4][4],int *x ,int *y){
   
   
    printf("\nEnter the coordinates (x,y) : ");
    scanf("%d,%d",&cood.x,&cood.y);
   if(((cood.x<1)||(cood.x>4))||((cood.y<1)||(cood.y>4))){
    do{
        printf("\n\nINVALID INPUT!!! pls enter again");
        printf("\nEnter the coordinates (x,y) : ");
        scanf("%d,%d",&cood.x,&cood.y);
    }while(((cood.x<1)||(cood.x>4))||((cood.y<1)||(cood.y>4)));
}
    printf("\n\n\n");
    if(arr[cood.y-1][cood.x-1]==1){
        arr[cood.y-1][cood.x-1]=0;        //change the 1 to 0 i.e ship is destroyed
        ary[cood.y-1][cood.x-1]='O';        //change the * to O i.e here you hit the ship
        *x-=1;                          //change the number of ship left in the matrix
        system("cls");
        printf("HIT!!!!!\n");
    }
    else if (ary[cood.y-1][cood.x-1]=='X'){
        printf("\nYou have already uncovered this tile!\n\n");
    }
    else{
        ary[cood.y-1][cood.x-1]='X';
        *y-=1;                              //decrease the number of attempt left
        system("cls");
        printf("Miss!!!!\n");     
    }

}
