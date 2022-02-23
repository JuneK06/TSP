#include <stdio.h>
#include <math.h>
#define N 5

double dist[N][N] = { {0} };

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
	int i, j;
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

	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++) {
			dist[i][j] = calc_dist(&toshi[i], &toshi[j]);
			dist[j][i] = dist[i][j];
		}

	return 0;
}