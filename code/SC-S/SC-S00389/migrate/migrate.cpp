#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long int x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long int n,d,ch,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		ch=x[2]-x[1];
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<=i-2;j++)
			{
				if(((x[i]-x[j])%d!=0)&&(x[i]-x[j]>0))
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}