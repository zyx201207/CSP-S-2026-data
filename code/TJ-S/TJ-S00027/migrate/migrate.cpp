#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N],cnt,zhizhen,comp;
struct node
{
	int l,r;
}b[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cnt=0,zhizhen=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		/*for(int i=1;i<=n;i++)
		{
			while(a[i]-a[zhizhen]>d)b[zhizhen].r=i-1,zhizhen++;
			b[zhizhen].r=i;b[i].l=zhizhen;
		}
		for(int i=zhizhen;i<=n;i++)b[i].r=n;
		zhizhen=1;
		for(int i=3;i<=n;i++)
		{
			while(a[i]-a[zhizhen]>=2*d||b[zhizhen].r-b[i].l+1<2)zhizhen++;
			if(i-zhizhen<3)continue;
			if(b[zhizhen].r-b[i].l+1!=2)continue;
			int lef=1,rig=1,leff=zhizhen,rigg=i;
			for(int j=b[zhizhen].l;j<zhizhen;j++)
			{
				if(a[zhizhen]-a[j]<=d&&a[zhizhen+1]-a[j]>d)
			}
		}*/
		for(int i=1;i<=n-3;i++)
		{
			if(a[i+3]-a[i]>=2*d)continue;
			if(a[i+2]-a[i]>d||a[i+3]-a[i+1]>d||a[i+3]-a[i]<=d)continue;
			int lef=1,rig=1;
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]-a[j]>d)break;
				if(a[i+1]-a[j]<=d)continue;
				lef++;
			}
			for(int j=i+4;j<=n;j++)
			{
				if(a[j]-a[i+3]>d)break;
				if(a[i+1]-a[j]<=d)continue;
				rig++;
			}
			cnt+=lef*rig;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

