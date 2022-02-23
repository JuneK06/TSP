#include <stdio.h>
#include <math.h>
#define N 5

typedef struct {
	int x;
	int y;
} Coord;

double calc_dist(Coord *a, Coord *b)
{
	return sqrt(pow((a->x) - (b->x), 2.0) + pow((a->y) - (b->y), 2.0));
}

int main(void)
{
	int i;
	Coord toshi[N] = {
		{80, 85},
		{60, 50},
		{50, 45},
		{30, 40},
		{20, 25},
	};

	for (i = 0; i < N; i++) {
		printf("%d : %d, %d\n", i, toshi[i].x, toshi[i].y);
	}

	

	return 0;
}