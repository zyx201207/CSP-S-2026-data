#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000006];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>x[i];
		int dis=x[1]-x[0];
		int u=1;
		/*for(int i=1;i<n;i++)if(x[i]-x[i-1]!=dis)
		{
			u=0;
			break;
		}*/
		if(dis>d)
		{
			cout<<"0\n";
			break;
		}
		/*int l=0,r=n-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(x[mid]<0)l=mid+1;
			else r=mid-1;
		}*/
		int p=0;
		while(x[p++]<0);
		int ans=0;
		ans+=max(n-p-2,0ll);
		ans+=max(p-2,0ll);
		cout<<ans<<'\n';
	}
	return 0;
}
//'^'
//涡轮增鸭，说到底，它们是SNiao23？反正我是SZi23QAQ。 
