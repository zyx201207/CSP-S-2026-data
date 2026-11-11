#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1,sum=0;
	ll ans=0;
	for(int r=1;r<=n;sum+=(r-l+1)*(a[r+1]-a[r]),r++){
		while(a[r+1]==a[r] && r+1<=n) r++;
		while(sum>m && l+1<=r) sum-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

