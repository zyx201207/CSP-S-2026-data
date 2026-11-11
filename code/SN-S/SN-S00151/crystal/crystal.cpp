#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
ll n,m,ans=1,a[N],prf[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		prf[i]=prf[i-1]+a[i];
	for(int i=2;i<=n;i++)
	{
		int l=1,r=i-1,p=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if (a[i]*(i-mid)-(prf[i-1]-prf[mid-1])<=m)
			{
				p=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		ans=max(ans,(ll)(i-p+1));
	}
	cout<<ans<<"\n";
}
