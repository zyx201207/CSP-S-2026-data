#include<bits/stdc++.h>//T1
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int L=1;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+(i-L)*(a[i]-a[i-1]);
		if(b[i]>m)
		{
			while(L+1<=n&&b[i]-(a[i]-a[L])>m)
			{
				b[i]-=(a[i]-a[L]);
				L++;
			}
			b[i]-=(a[i]-a[L-1]);
			L++;
		}
		else
		{
			while(L-1&&b[i]+(a[i]-a[L])<=m)
			{
				b[i]+=(a[i]-a[L]);
				L--;
			}
		}
		ans=max(i-L+1,ans);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 8
-3 -1 2 2 7
28-10=18
18-8=10
10-5=5
*/
