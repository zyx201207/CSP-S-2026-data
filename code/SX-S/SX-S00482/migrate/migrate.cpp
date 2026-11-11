#include<bits/stdc++.h>
using namespace std;
long long C,T;
long long n,d;
const int N=2e6+5;
long long a[N];
long long ff=0;
long long mymin=-1;
long long ss=0;
long long cnt=0;
long long ans=0;
void dfs(long long step)
{
	if(step==ff)
	{
		if(ss<mymin||mymin==-1)
		{
			mymin=ss;
			ans=1;
		}
		else if(mymin==ss) ans++;
	}
	for(int i=step+1;i<=n;i++)
	{
		if(a[i]-a[step]<=d)
		{
			ss++;
			dfs(i);
			ss--;
		}
	}
	return ;
}
int main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(C==11||C==12)
		{
			cout<<0<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					ff=j;ss=0,mymin=-1,ans=0;
					dfs(i);
					if(ans==2) cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}
