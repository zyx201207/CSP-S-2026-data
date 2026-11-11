#include <bits/stdc++.h>
#define int long long
#define mid ((P[I].l + P[I].r) >> 1)
#define lson (I << 1)
#define rson ((I << 1) | 1)
using namespace std;
using namespace chrono;

namespace FASTIO
{
	void read(int &x)
	{
		x = 0;
		int f = 1;
		char c = getchar();
		while(!('0' <= c && c <= '9'))
		{
			if('-' == c)
				f = -1;
			c = getchar();
		}
		while('0' <= c && c <= '9')
		{
			x = (x << 3) + (x << 1) + (c ^ '0');
			c = getchar();
		}
		x *= f;
	}
}

const int N = 5e5 + 5;
int n;
int A[N];
int m;

void INPUT()
{
	FASTIO::read(n);
	FASTIO::read(m);
	for(int i = 1; i <= n; i ++)
		FASTIO::read(A[i]);
}

int C[N];
struct info
{
	int l, r;
	int s;
	int tnum = 0;
	int num = 0;
};
struct SegTree
{
	info P[N * 4];
	inline void Build(int I, int L, int R)
	{
		P[I].l = L;
		P[I].r = R;
		P[I].s = R - L + 1;
		if(L == R)
		{
			P[I].num = C[L];
			return;
		}
		
		Build(lson, L, mid);
		Build(rson, mid + 1, R);
		P[I].num = P[lson].num + P[rson].num;
	}
	inline void Change(int I, int L, int R, int val)
	{
		if(L <= P[I].l && P[I].r <= R)
		{
			P[I].num += val * P[I].s;
			P[I].tnum += val;
			return;
		}
		
		P[lson].num += P[I].tnum * P[lson].s;
		P[lson].tnum += P[I].tnum;
		P[rson].num += P[I].tnum * P[rson].s;
		P[rson].tnum += P[I].tnum;
		P[I].tnum = 0;
		if(L <= mid)
			Change(lson, L, R, val);
		if(mid < R)
			Change(rson, L, R, val);
		P[I].num = P[lson].num + P[rson].num;
	}
	inline int Query(int I, int L, int R)
	{
//		printf("[%lld, %lld]:%lld\n", P[I].l, P[I].r, P[I].num);//
		if(L <= P[I].l && P[I].r <= R)
		{
//			printf("[%lld, %lld]:%lld\n", P[I].l, P[I].r, P[I].num);//
			return P[I].num;
		}
		
		P[lson].num += P[I].tnum * P[lson].s;
		P[lson].tnum += P[I].tnum;
		P[rson].num += P[I].tnum * P[rson].s;
		P[rson].tnum += P[I].tnum;
		P[I].tnum = 0;
		int res = 0;
		if(L <= mid)
			res += Query(lson, L, R);
		if(mid < R)
			res += Query(rson, L, R);
		return res;
	}
	inline int Found(int I, int val)
	{
		if(P[I].l == P[I].r)
		{
			return P[I].l;
		}
		
		P[lson].num += P[I].tnum * P[lson].s;
		P[lson].tnum += P[I].tnum;
		P[rson].num += P[I].tnum * P[rson].s;
		P[rson].tnum += P[I].tnum;
		P[I].tnum = 0;
		if(P[lson].num > val)
			return Found(lson, val);
		else
			return Found(rson, val - P[lson].num);
	}
} Tr;
void PREPAR()
{
	sort(A + 1, A + n + 1, [&](int a, int b)
		{
			return a > b;
		});
	for(int i = 1; i <= n; i ++)
	{
		C[i] = A[1] - A[i];
//		printf("%lld ", C[i]);//
	}
//	puts("\n");//
	Tr.Build(1, 1, n);
}

int Ans;
void GETANS()
{
	for(int i = 1; i <= n; i ++)
	{
//		printf("visiting %lld\n", i);//
		int nc = Tr.Query(1, i, i);
		Tr.Change(1, i, n, -nc);
		if(Tr.P[1].num <= m)
		{
//			printf("sum is %lld\n", Tr.P[1].num);//
//			printf("Ans <- %lld - %lld + 1\n", n, i);//
			Ans = max(Ans, n - i + 1);
		}
		else
		{
//			printf("Ans <- %lld - %lld\n", Tr.Found(1, m), i);//
			Ans = max(Ans, Tr.Found(1, m) - i);
		}
	}
}

void OUTPUT()
{
	cout << Ans;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	INPUT();
	PREPAR();
	GETANS();
	OUTPUT();
	
	return 0;
}