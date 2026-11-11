#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m;
int a[N];
int ma = 0;
void dfs(int cur,int d,int sum,bool c,bool f)
{
	if(d == n+1||cur==m+1)
		return ;
	if(c == 1)
	{
		if(sum == 0)
		{
			f= 1;
			sum = a[d];
		}
		else
		{
			sum = (sum&a[d]);
			f = 0;
			ma = max(ma,sum);
		}
		
		
		
	}
	dfs(cur+1,d+1,sum,1,f);
	dfs(cur,d+1,sum,0,f);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n  >> m;
	for(int i= 1;i<=n;i++)
	{
		cin >> a[i];
	} 
	dfs(0,1,0,1,0);
	dfs(0,1,0,0,0);
	
	
	
	cout<<ma;
	return 0;
}
