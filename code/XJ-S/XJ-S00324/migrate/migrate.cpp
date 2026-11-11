#include <bits/stdc++.h>
using namespace std;
long long a[2000005],d,ans,cnt;
int c,n,minn;
void dfs(int t,int pos,int num)
{
	if(pos==t)
	{
		if(num==minn) cnt++;
		if(num<minn)
		{
			minn=num;cnt=1;
		}
		//cout<<num<<endl;
		return;
	}
	for(int i=pos+1;i<=t;i++)
	{
		if(a[i]-a[pos]<=d) 
		{
			//cout<<i<<" "<<num<<endl;
			dfs(t,i,num+1);
		}
	}
}
void solve()
{
	int i,j;
	cin>>n>>d;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=0;
	if(c==1||c==2)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+3;j<=n;j++)
			{
				cnt=0,minn=n+1;
				dfs(j,i,0);
				if(cnt==2) ans++;
			}
		}
	}
//	else if(c==11||c==12)
//	{
//		
//	}
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
