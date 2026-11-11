#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;cin>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	ll ans=1,sum=0;
	for(ll l=1,r=2;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(l<r&&sum>m)sum-=a[r]-a[l],l++;
		if(sum<=m&&r-l+1>ans)ans=r-l+1;
	}
	cout<<ans<<endl;
	return 0;
} 
