#include<algorithm>
#include<iostream>

using namespace std;

typedef long long LL;
const int N = 2e6 + 6;

int can[N] = {0};
LL p[N] = {0};

LL d;
int n;
int c , t;

LL ans = 0;

void build()
{
	int r = 2;
	LL dis = 0;
	
	for(int l = 1;l <= n;++l)
	{
		while(r <= n && dis + (p[r] - p[r - 1]) <= d)
		{
			dis += p[r] - p[r - 1];
			++r;
		}
		
		
		
		can[l] = r - 1;
		if(can[l] == l)
		{
			can[l] = -1;
		}
		dis -= p[l + 1] - p[l];
		
	}
	
	return ;
}

int dfs(int x , int y , int sum , int mx)
{
	if(x == y)
	{
		return 1;
	}
	
	if(x > y)
	{
		return 0;
	}
	
	if(sum >= mx)
	{
		return 0;
	}
	
	int res = 0;
	
	for(int i = x + 1;i <= can[x];++i)
	{
		res += dfs(i , y , sum + 1 , mx);
		if(res >= 3)
		{
			return 3;
		}
	}
	
	return res;
	
}

inline int check_2(int x , int y)
{
	int sum = 0;
	
	int p = x;
	
	while(p < y)
	{
		if(can[p] == -1)
		{
			return 0;
		}
		p = can[p];
//		if(y == 5)
//		{
//		cout << p << endl;
//		}
		sum++;
	}
	
	
	
//	if(y == 4)
//	{
//		cout << "!!!" << sum << "!!!" << endl;
//	}
	
	int res = dfs(x , y , 0 , sum);
	
//	if(y == 4)
//	{
//		cout << "!!!!" << res << "!!!!" << endl;
//	}
	
	if(res == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

inline LL check(int id)
{
	if(id == 1 || id == 2 || id == 3)
	{
		return 0;
	}
	
	LL res = 0;
	for(int i = 1;i <= id - 3;++i)
	{
//		if(id == 5)
//		{
//			cout << i << endl;
//		}
		int r = check_2(i , id);
//		if(id == 4)
//		{
//			cout << i << "  " << id << "  " << r << endl;
//		}
//		if(r == 1)
//		{
//			cout << i << "   " << id << endl;
//		}
		res += r;
	}
	
	return res;
}

void sol()
{
	for(int i = 1;i <= n;++i)
	{
		ans += check(i);
	}
	return ;
}

void my_clear()
{
	for(int i = 0;i < N;++i)
	{
		p[i] = 0;
		can[i] = 0;
	} 
	ans = 0;
	return ;
}

int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	
	cin >> c >> t;
	int tt = t;
	while(t)
	{
		if(tt != t)
		{
			return 0;
		}
		cin >> n >> d;
		
		for(int i = 1;i <= n;++i)
		{
			cin >> p[i];
		}
		
		build();
		
//		cout << "!!!" << n << endl;
		
//		for(int i = 1;i <= n;++i)
//		{
////			cout << i << "   ";
//			cout << can[i] << endl;
//		}
		
		sol();
		
		cout << ans << endl;
		
		my_clear();
		--t;
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
/*
fre
fcl
can
p
ans
*/
