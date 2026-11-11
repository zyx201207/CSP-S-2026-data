#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int c,t,n,d,a[N],corr,cnt,ans;
void dfs(int x,int y,int step)
{
//	cout<<x<<' ';
	if(x > y) return ;
	if(x == y)
	{
		if(step < corr) 
		{
			cnt = 1;
			corr = step;
			return;
		}
		else cnt ++;
//		cout<<endl;
		return ;
	}
//	if(x + 1 == y) 
//	{
//		if(abs(a[y] - a[x]) <= d)
//		{
//			dfs(y,y,step + 1);
//		}
//		else return;
//	}
	int tmp = x + 1;
	while(abs(a[tmp] - a[x]) <= d && tmp <= y)
	{
		dfs(tmp,y,step + 1);
		tmp ++;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t -- )
	{
		cnt = 0;
		cin>>n>>d;
		if(n <= 3)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				corr = 0x3f3f3f3f;
				cnt = 0;
				dfs(i,j,0);
//				cout<<corr<<endl;
				if(cnt == 2)
				{
					ans ++;
//					cout<<i<<' '<<j<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/