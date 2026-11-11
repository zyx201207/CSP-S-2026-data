#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,m,a[N],ans[N],sum,cnt;
void dfs(int d,int ma,int b)
{
	if(d>=ma)
	{
//		ans[ma]=min(ans[ma],b);
		if(ans[ma]>b)
		{
			ans[ma]=b;
			sum=1;
		}
		else{
			sum++;
		}
		return ;
	}
	for(int i=d+1;i<=ma;i++)
	{
		if(a[i]-a[d]<=m)
		{
			dfs(i,ma,b+1);
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	/*
	0 2
	5 3
	-2 -1 0 1 2
	6 2
	-4 -3 -2 -1 3 6
	
	*/
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			sum=0;
			ans[i]=INT_MAX;
			dfs(a[1],i,0);
//			cout<<ans[i]<<" ";
			if(ans[i]==2) cnt++;
		}
//		cout<<"\n";
		cout<<cnt<<"\n";
	}
	return 0;
}