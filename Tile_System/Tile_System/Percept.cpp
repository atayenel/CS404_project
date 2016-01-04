#include "Percept.h"

Percept::Percept()
{
	size=5;

}

Percept::Percept(int s)
{
	size=s;
}

Percept::~Percept(void)
{
}

void Percept::CreateWorld()
{
	//There is 1 wumpus
	World[2][0].Wumpus=true;

	//3 pits
	World[2][2].Pit=true;
	World[3][3].Pit=true;
	World[0][2].Pit=true;

	//1 Gold
	World[4][4].Gold=true;

	setRules();
}
void Percept::setRules()
{
	for(int k=0;k<5;k++)
	{
		for(int j=0;j<5;j++)
		{
			if(World[k][j].Pit)
			{
				setAdjBreeze(k,j); //Set adjacent squares to Breeze
			}
			else if(World[k][j].Wumpus)
			{
				setAdjSmell(k,j);	//Set adjacent squares to Smell
			}
			else if(World[k][j].Gold)	//set square with gold to true
			{
				World[k][j].Glitter=true;
			}

		}
	}
}
void Percept::setAdjBreeze(int r,int c)
{
		if(r-1>-1)
		{
			World[r-1][c].Breeze=true;
		}
		if(r+1<size)
		{
			World[r+1][c].Breeze=true;
		}
		if(c+1<size)
		{
			World[r][c+1].Breeze=true;
		}
		if(c-1>-1)
		{
			World[r][c-1].Breeze=true;
		}
}
void Percept::setAdjSmell(int r,int c)
{
	if(r-1>-1)
		{
			World[r-1][c].Smell=true;
		}
		if(r+1<size)
		{
			World[r+1][c].Smell=true;
		}
		if(c+1<size)
		{
			World[r][c+1].Smell=true;
		}
		if(c-1>-1)
		{
			World[r][c-1].Smell=true;
		}
}
Percept Percept::operator=(Percept other)
{
	Percept myPercept;
	for(int r=0;r<size;r++)
	{
		for(int c=0;c<size;c++)
		{
			myPercept.World[r][c]=other.World[r][c];
		}
	}
	return myPercept;
}