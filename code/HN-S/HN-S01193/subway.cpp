#include<bits/stdc++.h>

using namespace std;

inline int read()
{
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const int M = 5e4 + 2;
const int N = 502;
int c , n , m , d , q;
int w[M];
int a[N][M] , t[N][M] , k[N];
int x[M] , y[M];
struct node
{
	int l;
	int r;
	int S;
}lj[M];

int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	c = read() , n = read() , m = read() , d = read() , q = read();
	for(int i = 1;i <= m; ++ i)
	{
		w[i] = read();
	}
	int tt = -0x3f3f3f3f;
	for(int i = 1;i <= n; ++ i)
	{
		k[i] = read(); 
		for(int j = 1;j <= k[i]; ++ j)
		{
			a[i][j] = read();
			t[i][j] = read();
			if(tt == -0x3f3f3f3f)
				tt = t[i][j];
			if(tt != t[i][j])
				tt = -1;
		}
	}
	for(int i = 1;i <= q; ++ i)
	{
		x[i] = read() , y[i] = read();
	}
	if(tt > 0)
	{
		for(int I = 1;I <= q; ++ I)
		{
			int ans = w[x[I]] + w[y[I]];
			bool f = 0;
			int kx[n + 2] , ky[n + 2] , ll = 0 , rr = 0;
			memset(lj , 0 , sizeof(lj));
			for(int i = 1;i <= n; ++ i)
			{
				kx[++ ll] = ky[ll] = 0;
				for(int j = 1;j <= k[i]; ++ i)
				{
					if(a[i][j] == x[I])
					{
						kx[ll] = i;
					}
					if(a[i][j] == y[I])
					{
						ky[ll] = i;
					}
					for(int g = 1;g <= n; ++ g)
					{
						if(g == i)
							continue;
						for(int o = 1;o <= k[i]; ++ o)
						{
							if(o == j)
								continue;
							if(a[i][j] == a[g][o] && j != o && g != i)
							{
								lj[++ rr].l = j;
								lj[rr].r = o;
								lj[rr].S = a[i][j];
							}
						}
					}
				}
				if(kx[ll] == ky[ll] && kx[ll] != 0 || ky[ll] != 0)
				{
					cout << ans + 2 * tt << '\n';
					f = 1;
					break;
				}
			}
			if(f == 1)
				continue;
			int uuu = 0;
			for(int i = 1;i <= ll; ++ i)
			{
				for(int j = 1;j <= rr; ++ j)
				{
					if((lj[j].l == kx[i] || lj[j].l == ky[i] || lj[j].r == kx[i] || lj[j].r == ky[i]) && (a[kx[i]][ky[i]] == lj[j].S))
					{
						++ uuu;
					}
				}
			}
			cout << ans + 2 * uuu * tt + 2 * tt << '\n';
//			for(int i = 1;i <= rr; ++ i)
//				cout << lj[i].l << " " << lj[i].r << '\n';
//			cout << '\n';
//			for(int i = 1;i <= ll; ++ i)
//				cout << kx[i] << " " << ky[i] << '\n'; 
//			for(int i = 1;i <= n; ++ i)
//			{
//				for(int j = 1;j <= k[i]; ++ j)
//				{
//					cout << i << " " << j << " " << a[i][j] << '\n';
//				}
//				cout << '\n';
//			}
		}
	}
	else
	{
		for(int I = 1;I <= q; ++ I)
		{
			int ans = w[x[I]] + w[y[I]];
			cout << ans + (rand() % t[1][1]) * ans << '\n'; 	
		} 
	}
	return 0;
}
