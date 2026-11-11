#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,d,t,a[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i];
			
		}
		int num=a[2]-a[1],flag=1;
		for(int i = 3;i<=n;i++)
		{
			if(a[i]-a[i-1]!=num)
			{
				flag=0;
				break;
			}
			
		}
		
		if(flag)
		{
			int num2=num/d,ans=0;
			for(int i = 1;i<n;i++)
			{
				if((n-i)%num2!=0)
				{
					ans+=i;
				}
				
				
				
			}
			cout<<ans<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
