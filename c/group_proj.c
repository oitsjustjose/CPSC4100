
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 32
#define COL 32

char grid[ROW][COL];
int xBound = (ROW);
int yBound = (COL);

void draw_diagonal(int x, int y, int size, char dir)
{ 
	if(x<1 || y<1 || size<1 /*|| (y + size)>yBound || x + size > xBound*/)
	{
	}
	else
	{
		if(dir=='l')
		{
			int i =0;
			while(i<size)
			{
				int j = (size - 1);
				while(j >= 0)
				{
					if (i==j)
					{
						grid[(y+j)][(x-i)] = '/';
					}
					j -= 1;
				}
				i += 1;
			}
		}
		else
		{
			for (int i =0; i<size; i++)
			{
				for(int j = 0; j<size; j++)
				{
					if (i==j)
					{
						grid[(y+j)][(x+i)] = '\\';
					}
				}
			}
		}
	}
}
void printErr(char cmd[])
{
	printf("Command: ");
	for (int i = 0;i<strlen(cmd);i++)
	{
		printf("%c", cmd[i]);
	}
	printf(" not found/n");
}
void print_grid()
{
	for(int i = 0; i<ROW;i++)
	{
		for(int j = 0; j<COL; j++)
		{
			printf("%c",grid[i][j]);
		}
		printf("\n");
	}
}

void draw_filled_box(int x, int y, int w, int h)
{	
	if(x<0 || y<0 || w<1 || h<1)
	{
	}
	else
	{
		//check invalid
		if(y>yBound || x>xBound)
		{
			
		}
		else
		{
			for(int i = 0; i<w; i++)
			{
				for (int j = 0; j<h;j++)
				{
					if((y + h)< yBound && (x + w)< xBound)
					{
					grid[(y+j)][(x+i)] = '#';
					}
				}
			}
		}
	}

		
}

void draw_empty_box(int x,int y, int w, int h)
{
	//check invalid
	if(x<0 || y<0 || w<1 || h<1)
	{
	}
	else
	{
		//check invalid
		if(y>yBound || x>xBound || (y + w)>yBound || (x + h)> xBound)
		{
			
		}
		else
		{
			for(int i = 0; i<w; i++)
			{
				for (int j = 0; j<h; j++)
				{
					if(i == 0 || i == (w-1))
					{
						grid[(y + j)][(x + i)] = '#';
						
					}
					else
					{
						if(j == 0 || j == (h-1))
						{
							grid[( y + j)][(x + i)] = '#';
							
						}
					}
				}
			}
		}
	}
	
	
}
void  draw_vertical(int x, int y, int size)
{
	if(x<1 || y<1 || size<1 || (y + size) > yBound)
	{
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			grid[(y + i)][x] = '|';
		}
	}
}
void  draw_horizontal(int x, int y, int size)
{
	if(x<1 || y<1 || size<1 || (x + size) > xBound)
	{
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			grid[y][(x + i)] = '-';
		}
	}
}

void fill(int x, int y, char c)
{
	
	if(x<1 || y<1)
	{
	}
	else
	{
	//check every surrounding index that is not Out o bounds
		if(grid[y][x] == ' ') {
			grid[y][x] = c;
			//printf("X:%d Y:%d\n", x,y);
		}
		
		if ((y-1)>0 && grid[(y-1)][x] == ' ') fill(x, (y-1), c);
		if ((y+1)<yBound && grid[(y+1)][x] == ' ') fill(x, (y+1), c);
		if ((x-1)>0 && grid[y][(x-1)] == ' ') fill(x-1, y, c);
		if ((x+1)<xBound && grid[y][x+1] == ' ') fill(x+1, y, c);
	}
}




int main(int argc, char *argv[])
{
	for(int i = 0;i<ROW; i++)
	{
		for(int j=0;j<COL;j++)
		{
		grid[i][j]=' ';
		}
	}
	static const char filename[] = "../instructions.txt";
	FILE *file = fopen ( filename, "r" );
   if ( file != NULL )
   {
	   
      char line [ 128 ]; /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
		 char params[5][128];
		 int count =0;
		// check for errors
		char *r = line;
		char *tok = r, *end = r;
		while (tok != NULL) {
		strsep(&end, ",");
		
		//puts(tok);
		strcpy(params[count],tok);
		count +=1;
		tok = end;
		}
		
		if(strcmp(params[0], "draw_horizontal_line")==0)
		{
			draw_horizontal(atoi(params[1]),atoi(params[2]),atoi(params[3]));
		}
		else
		{
			if(strcmp(params[0], "draw_diagonal_line")==0)
			{
				char dir = params[4][1];
				draw_diagonal(atoi(params[1]),atoi(params[2]),atoi(params[3]),dir);
			}
			else
			{
				if(strcmp(params[0], "draw_vertical_line")==0)
				{
					draw_vertical(atoi(params[1]),atoi(params[2]),atoi(params[3]));
				}
				else
				{
					if(strcmp(params[0], "draw_empty_box")==0)
					{
						draw_empty_box(atoi(params[1]),atoi(params[2]),atoi(params[3]),atoi(params[4]));
					}
					else
					{
						if(strcmp(params[0], "draw_filled_box")==0)
						{
							draw_filled_box(atoi(params[1]),atoi(params[2]),atoi(params[3]),atoi(params[4]));
						}
						else
						{
							if(strcmp(params[0], "fill")==0)
							{
								char filler = params[3][1];
								
								fill(atoi(params[1]),atoi(params[2]),filler);
							}
						}
						
					}
				}
			}
		}

		
		//free(r);
      }
	  print_grid();
      fclose ( file );
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }
  // return 0;
}