#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
ll n,m,a[N],cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=1;
	while(l<=r){
		while((r-l+1)*(a[r+1]-a[r])+cnt<=m&&r<n){
			cnt+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		ans=max(ans,r-l+1);
		cnt-=a[r]-a[l];
		l++;
	}
	cout<<ans<<endl;
	return 0;
} 
