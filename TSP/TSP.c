#include <stdio.h>
#include <math.h>
#define N 5

double dist[N][N] = { {0} };
double best = 0;
int comb[N];
int cnt[N + 1] = { 0 };
int index[N];

typedef struct {
	int x;
	int y;
} Coord;

double calc_dist(Coord *a, Coord *b)
{
	return sqrt(pow((double)(a->x) - (b->x), 2.0) + pow((double)(a->y) - (b->y), 2.0));
}

void swap(int i)
{
	int tmp = comb[0];
	comb[0] = comb[i];
	comb[i] = tmp;
}

void sum()
{
	double tmp = 0;
	int i;
	for (i = 0; i < N; i++) {
		tmp += dist[comb[i]][comb[(i + 1) % N]];
	}
	if (best > tmp) {
		best = tmp;
		for (i = 0; i < N; i++) {
			index[i] = comb[i];
		}
	}
}

void count(int n)
{
	cnt[n]++;
	if (cnt[n] > n) {
		cnt[n] = 0;
		count(n + 1);
	}
	else if (cnt[N] == 0) {
		swap(n);
		sum();
	}
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
		comb[i] = i;
		printf("%d : %d, %d\n", i, toshi[i].x, toshi[i].y);
	}

	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++) {
			dist[i][j] = calc_dist(&toshi[i], &toshi[j]);
			dist[j][i] = dist[i][j];
		}

	for (i = 0; i < N; i++) {
		best += dist[i][(i + 1) % N];
	}

	do {
		count(1);
	} while (cnt[N] == 0);

	printf("最短距離：%f\n", best);
	printf("経路：");
	for (i = 0; i < N; i++) {
		printf("%d→", index[i]);
	}
	printf("%d\n", index[0]);

	return 0;
}