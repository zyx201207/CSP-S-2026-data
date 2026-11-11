#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5; 
int c,t;
long long a[N];
int n,d;
bool check(int u,int v)//buhui... 
{
	bool f=0;
	for(int i=u;i<=v;i++)
	{
		if(a[i]-a[u]<d)
		{
			break;
		}
		f=1;
	}
	return f;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n<=3)
		{
			cout<<0<<"\n";
		}
		else if(c<=10)
		{
			long long ans=0;
			for(int i=1;i<=(n-3);i++)
			{
				for(int j=i+3;j<=n;j++)
				{
					if(check(i,j)==1)
					{
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		} 
		else
		{
			int cha=a[2]-a[1];
			int x=d/cha;
			x++;
			cout<<n-x<<"\n";
		}
	}
	return 0;
}
