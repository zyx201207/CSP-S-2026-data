#include<bits/stdc++.h> 
using namespace std;
int c,t,ans,num;
int a[100000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			int p=0;
			cin>>p;
			if(p/d&&p%d-1==0)
			{
				ans=ans+1;
			}
			
		}
	}
	cout<<ans<<endl;

	return 0;
}
