#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000001;
int c,T;
int n,d,x[N];
int to,mi,su;
void dfs(int now,int dep)
{
	if(now==to)
	{
		if(dep<mi)
		{
			mi=dep;
			su=1;
		}	
		else if(dep==mi)
			su++;
		return;
	}	
	for(int i=now+1;i<=to;i++)
	{
		if(x[i]-x[now]>d)
			break;
		dfs(i,dep+1);
	}	
}	
signed main()
{
	//freopen("migrate4.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	for(int TT=1;TT<=T;TT++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				mi=N,su=0,to=j;
				dfs(i,0);
				if(su==2)
					ans++;
			}	
		cout<<ans<<'\n';
		//if(TT==5)
		//	cout<<x[2]-x[1]<<" "<<d<<" "<<n<<'\n';
		/*if(n<=1)
			cout<<0<<'\n';
		else
		{
			int t=x[2]-x[1];
			if(d<3*t && d>=2*t)
				cout<<max(0ll,n-3)<<'\n';
			else
				cout<<0<<'\n';
		}*/
	}	
}	
