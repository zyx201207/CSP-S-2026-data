#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+9;
ll n,m,a[N],sum;
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int l=1,r=0;l<=n;l++){
		while(r<=n&&m>=a[r]*(r-l+1)-sum)r++,sum+=a[r];
		ans=max(ans,r-l);
		sum-=a[l];
	}
	cout<<ans;
	return 0;
}
