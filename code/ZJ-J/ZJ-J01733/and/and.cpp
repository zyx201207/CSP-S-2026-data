#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool choose[N];
void dfs(int now)
{
	if(now==n+1)
	{
		int sum=0,len=0;
		for(int i=1;i<=n;i++)
		{
			if(choose[i])
			{
				if(!sum) sum=a[i];
				len++;	
			}
		}
		if(len!=m) return;
		for(int i=1;i<=n;i++)
		{
			if(choose[i])
			{
				sum=(sum&a[i]);
			}
		}
		ans=max(ans,sum);
		return;
	}
	choose[now]=1;
	dfs(now+1);
	choose[now]=0;
	dfs(now+1);
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}	
//8 2
//0 1 2 3 4 5 6 7

//4 2
//3 15 12 12

//5 3
//31 3 1 15 7