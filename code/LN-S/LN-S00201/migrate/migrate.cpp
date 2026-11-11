#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005],c,t;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				int op=1;
				for(int k=i;k<=j-1;k++)
				{
					if(a[k+1]-a[k]>d)
					{
						op=0;
						break;
					}
				}
				if(op==1)
				{
					int cnt=0;
					for(int k=i;k<=j-3;k++)
					{
						if(((a[i+1]-a[i])+(a[i+2]-a[i+1])<=d)&&((a[i+2]-a[i+1])+(a[i+3]-a[i+2])<=d)&&(a[i+3]-a[i]>d)) cnt++;
						if(cnt>=2) break;
					}
					if(cnt==1) ans++;
				}
			}
		}
		cout<<ans<<endl;
		memset(a,0,sizeof(a));
	}
	return 0;
}
