#include<stdio.h>
#include<conio.h>
#define LT 218
#define HL 196
#define VL 179
#define RT 191
#define TT 194
#define BT 193
#define LST 195
#define RST 180
#define CROSS 197
#define SP 32
#define LB 192
#define RB 217
#define WIDTH 3
#define HEIGHT 1
#define DIM 9
#define TRUE 1
#define FALSE 0
int count=0;
void drawDabba()
{
  int br,bc,ctr,ctr1,ctr2;
  bc = ( 80  - ( DIM * ( WIDTH + 1 ) ) )  / 2;
  br = ( 25 - ( DIM * ( HEIGHT + 1) ) )  / 2;
  gotoxy(bc,br);
  printf("%c",LT);
  for( ctr1 =  0 ; ctr1 < DIM ; ctr1++ )
  {
     for( ctr= 0 ; ctr < WIDTH ; ctr++)
	printf("%c",HL);
     printf("%c",TT);
  }
  printf("\b%c",RT);
  for( ctr2 = 0 ; ctr2 < DIM ; ctr2++)
  {
  gotoxy(bc,++br);
  for( ctr1 = 0 ; ctr1 <= DIM ; ctr1++ )
  {
     printf("%c",VL);
     for( ctr = 0  ; ctr < WIDTH ; ctr++)
       printf(" ");
  }
  gotoxy(bc,++br);
  printf("%c",LST);
  for( ctr1 =  0 ; ctr1 < DIM ; ctr1++ )
  {
     for( ctr= 0 ; ctr < WIDTH ; ctr++)
	printf("%c",HL);
    printf("%c",CROSS);
  }
  printf("\b%c",RST);
  }
  gotoxy(bc,br);
  printf("%c",LB);
  for( ctr1 =  0 ; ctr1 < DIM ; ctr1++ )
  {
     for( ctr= 0 ; ctr < WIDTH ; ctr++)
	printf("%c",HL);
     printf("%c",BT);
  }
  printf("\b%c",RB);

}

void placeNum(int grid[DIM][DIM],int row , int col)
{
   int bc,br;
   bc = ( 80  - ( DIM * ( WIDTH + 1 ) ) )  / 2;
  br = ( 25 - ( DIM * ( HEIGHT + 1) ) )  / 2;
      bc += 2;
      br++;

   gotoxy( bc + ( WIDTH + 1) * col , br+(HEIGHT +1)*row);
   printf("%d",grid[row][col]);

}
#define SAFE 1
#define NOTSAFE 0


#define SAFE 1
#define NOTSAFE 0

int checkbox(int grid[DIM][DIM],int row, int col,int num){
	int r,c;
	for(r=0;r<3;r++){
	for(c=0;c<3;c++){
	if(grid[r+row][c+col]==num) return SAFE;
	}}
	return NOTSAFE;
}

int checkhori(int grid[DIM][DIM],int row,int num){
	int r,c;
	for(r=row,c=0;c<9;c++){
	if(grid[r][c]==num) return SAFE;}
	return NOTSAFE;
}

int checkverti(int grid[DIM][DIM],int col,int num){
	int r,c;
	for(r=0,c=col;r<9;r++) {
	if(grid[r][c]==num) return SAFE;}
	return NOTSAFE;

}
int isSafe(int grid[DIM][DIM],int row,int col,int num)
{
	int r,c;
	r = row-row%3;
	c = col-col%3;
    return !checkbox(grid,r,c,num)
			&& !checkhori(grid,row,num)
			&& !checkverti(grid,col,num);
}

int isNull(int grid[DIM][DIM],int *row,int *col){
for(*row=0;*row<DIM;(*row)++){
for(*col=0;*col<DIM;(*col)++){
if(grid[*row][*col]==0){
return TRUE;}
      }	}return FALSE;
}
int solve(int grid[DIM][DIM]) {

	int row = 0;
	int col = 0,num;
	count++;
	if (!isNull(grid,&row, &col)){
		return 1;
	}

	for (num = 1; num <= DIM; num++ ) {

		if (isSafe(grid,row, col, num)) {
			grid[row][col] = num;

			if (solve(grid)) {
				return 1;

			}

			grid[row][col] = 0;
		}
	}

	return 0;
}
#include<dos.h>
void main()
{
    int row,col;
    int grid[DIM][DIM]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
		      {5, 2, 0, 0, 0, 0, 0, 0, 0},
		      {0, 8, 7, 0, 0, 0, 0, 3, 1},
		      {0, 0, 3, 0, 1, 0, 0, 8, 0},
		      {9, 0, 0, 8, 6, 3, 0, 0, 5},
		      {0, 5, 0, 0, 9, 0, 6, 0, 0},
		      {1, 3, 0, 0, 0, 0, 2, 5, 0},
		      {0, 0, 0, 0, 0, 0, 0, 7, 4},
		      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    clrscr();
    drawDabba();
	if (solve(grid)) {
        for(row=0;row<DIM;row++)
        for(col=0;col<DIM;col++)
		placeNum(grid,row,col);
		gotoxy(1,2);
		printf("%d",count);
	} else {
		printf("no solution");
	}
    getch();

}

