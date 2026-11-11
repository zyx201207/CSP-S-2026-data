#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int x[N],n,d,minn=1e18,cnt,ans;
void check(int step,int num,int cn)
{
	if(num-step>d||step>num)return ;
	if(step==num)
	{
		minn=min(minn,cn);
		return ;
	}
	for(int i=1;i<=d;i++)check(step+i,num,cn+1);
	return ;
}
void bfs(int step,int num,int cn)
{
	if(num-step>d||step>num)return ;
	if(step==num&&cn==minn)
	{
		cnt++;
		return ;
	}
	for(int i=1;i<=d;i++)bfs(step+i,num,cn+1);
	return ;	 
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt=0;
				minn=1e18;
				if(x[j]-x[i]<d)continue;
				check(x[i],x[j],0);
				minn++;
				bfs(x[i],x[j],0);
				if(minn==1e18)continue;
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

