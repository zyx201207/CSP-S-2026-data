#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
int ans=1,l=1,r=1,now=0,sum;
bool cmp(const int &x,const int &y){return x<y;}
signed main(void)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	while(l<=r&&l<=n&&r<=n)
	{
		if(now<=m)ans=max(ans,(r-l+1));
		if(now<=m)
		{
			r++;
			now+=(r-l)*(a[r]-a[r-1]);
			sum+=a[r]-a[r-1];
		}
		else
		{
			l++;
			now-=sum;
			sum-=a[l]-a[l-1];
		}
	}
	cout<<ans<<endl;
	return 0;
}