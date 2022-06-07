#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

double dist[N][N] = { {0} }; /*都市間の距離*/
double best = 0;             /*最短経路の長さ*/
int index[N];                /*最短経路を格納するための配列*/

typedef struct {
	int x;
	int y;
} City;

double calc_dist(City* a, City* b)
{
	return sqrt(pow((double)(a->x) - (b->x), 2.0) + pow((double)(a->y) - (b->y), 2.0));
}

void swap(int i, int j, int v[])
{
	int tmp = v[j];
	v[j] = v[i];
	v[i] = tmp;
}

/* 経路の距離を求める関数 */
void sum(int v[])
{
	double tmp = 0;
	int i;
	for (i = 0; i < N; i++) {
		tmp += dist[v[i]][v[(i + 1) % N]];
	}
	if (best > tmp) {
		best = tmp;
		for (i = 0; i < N; i++) {
			index[i] = v[i];
		}
	}
}

/* 全ての経路の組み合わせを求める関数 */
void route(int cnt, int v[])
{
	int i, j;
	int tmp[N];

	for (i = 0; i < N; i++) {
		tmp[i] = v[i];
	}

	tmp[cnt] = cnt;

	for (i = cnt; i > 0; i--) {
		/* デバック用 */
		for (j = 0; j < N; j++) {
			printf("%d", tmp[j]);
		}
		putchar('\n');

		if (cnt < N - 1) {
			route(cnt + 1, tmp);
		}
		else {
			sum(tmp);
		}

		if (cnt < 3 || i == 1) {
			break;
		}
		swap(i, i - 1, tmp);
	}
}

void main(void)
{
	int i, j;
	int v[N] = { 0 };
	City city[N] = {
		{80, 85},
		{60, 50},
		{50, 45},
		{30, 40},
		{20, 25},
	};

	/* 各都市の座標の表示 */
	for (i = 0; i < N; i++) {
		printf("%d : %d, %d\n", i, city[i].x, city[i].y);
	}

	/* 各都市間の距離を求める */
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++) {
			dist[i][j] = calc_dist(&city[i], &city[j]);
			dist[j][i] = dist[i][j];
		}

	/* bestに基準の距離を代入 */
	for (i = 0; i < N; i++) {
		best += dist[i][(i + 1) % N];
	}

	/* 最短経路を求める */
	route(1, v);

	/* 結果の表示 */
	printf("最短距離：%f\n", best);
	printf("経路：");
	for (i = 0; i < N; i++) {
		printf("%d→", index[i]);
	}
	printf("%d\n", index[0]);
}