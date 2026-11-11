#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],k,l,r,b[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	b[i]+=b[i-1]+a[i];
	l=1;
	r=1;
	while(l<=r&&r<=n)
	{
		k=a[r];
		while(l<=r)
		{
			ll len=r-l+1;
			ll sum=len*k;
			if(sum-(b[r]-b[l-1])>m)
			l++;
			else
			break;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
