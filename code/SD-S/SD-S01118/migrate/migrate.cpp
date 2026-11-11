#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long C,T,n,k,a[N],b[N],ans;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		ans=0;
		//memset(a,0,sizeof(a));
		//memset(b,0,sizeof(b));
		cin>>n>>k;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=upper_bound(a+1,a+1+n,a[i]+k)-a-1;
		}
		//cout<<b[1]<<" "<<b[2]<<"\n";
		if(C==11||C==12)
		{
			if(b[1]==1||b[1]==2)
			{
				
				ans=0;
			}
			else
			{
				if(n>b[1])
				{
					//cout<<T<<" ";
					ans=max(0ll,n-b[1]*2+3);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=2;i<=n;i++)
		{
			if(b[i-1]-i==1&&b[i]>b[i-1])ans++;
		}
		cout<<ans<<"\n";
//		for(int i=1;i<n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				
//			}
//		}
//		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/

