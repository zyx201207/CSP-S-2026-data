#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[10001];
int n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]-a[j]==d+1)
					ans++;
			} 
		} 
		cout<<ans<<endl;
	}
	return 0;
 } 
