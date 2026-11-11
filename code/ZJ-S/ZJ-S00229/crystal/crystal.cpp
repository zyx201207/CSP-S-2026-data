#include<bits/stdc++.h>
using namespace std;
const int maxN=5e5+10;
int n,l,ans;
unsigned long long m,cost;
long long a[maxN];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=1;ans=1;cost=0;
	for(int r=2;r<=n;r++)
	{
		cost+=(r-l)*(a[r]-a[r-1]);
		while(cost>m&&l<r)
		{
			cost-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}