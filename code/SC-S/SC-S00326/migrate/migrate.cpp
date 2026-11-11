#include<bits/stdc++.h>
using namespace std;

long long a[10000000];

long long pre[10000000];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,t,n,d,ans=0;
	cin>>c>>t;
	long long mi=1000000000000000000;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			pre[i]=pre[i-1]+abs(a[i]-a[i-1]);
		}
		if(c==12||c==11)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(d>pre[j]-pre[i]) continue;
					if(pre[3]-pre[1]<=d&&j-i==3)
					{
						ans++;
					}
				}
			}
		}
		else if(c==13||c==14)
		{
			ans=0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(d>pre[j]-pre[i]) continue;
					for(int z=i;z<=j;z++)
					{
						if(pre[z]-pre[i]>d&&z-i==1)
						{
							break;
						}
						else if(pre[z]-pre[i]<=d&&z-i>2)
						{
							break;
						}
						else if(pre[z]-pre[i]<=d&&j-z==1)
						{
							break;
						}
						else if(j-i==3&&pre[z]-pre[i]<=d&&j-z==1)
						{
							ans++;
							break;
						}
						else ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
} 
