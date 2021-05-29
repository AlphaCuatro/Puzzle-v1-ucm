#include "Coordenada.h"
using namespace std;

bool operator == (tCoor c1, tCoor c2)
{
	if ((c1.x == c2.x) && (c1.y == c2.y))
	{
		return true;
	}
	else return false;
}
bool operator != (tCoor c1, tCoor c2)
{
	if ((c1.x != c2.x) || (c1.y != c2.y))
	{
		return true;
	}
	else return false;
}
tCoor operator + (tCoor c1, tCoor c2)
{
	tCoor c3;
	c3.x = c1.x + c2.x;
	c3.y = c1.y + c2.y;
	return c3;
}