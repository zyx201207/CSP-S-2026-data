#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,a[524500],cnt,s[524500],ans=1,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]-a[i-1];
	ll r=1;
	for(ll l=1;l<=n;l++){
		while(cnt+s[r+1]*(r-l+1)<m&&r<n){
			cnt+=s[r]*(r-l+1);
			r++;
		}
		ans=max(ans,r-l+1);
		if(r>l){
			cnt-=a[r]-a[l];
		}else r++;
	}
	cout<<ans;
	return 0;
}

