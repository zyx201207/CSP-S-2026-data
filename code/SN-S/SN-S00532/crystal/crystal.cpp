#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll a[N],s[N],sum[N];
int maxn=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;ll m;cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=(a[i]-a[i-1])*(i-1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+s[i];
	int l=1;ll ans=0;
	//for(int i=1;i<=n;i++)  cout<<sum[i]<<" ";
	//cout<<"\n";
	for(int r=1;r<=n;r++)
	{
		ans=sum[r]-sum[l]-(l-1)*(a[r]-a[l]);
		while(l<=r&&ans>m)
		{
			ans-=sum[l],l++;
		}
		if(l<=r)  maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
	return 0;
}
