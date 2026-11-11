#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005],b[200005][31],sum[31],wh=-1,ans,idx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<ll>());
	for(ll i=1;i<=n;i++){
		for(ll k=30;k>=0;k--){
			if((a[i]>>k)&1)b[i][k]=1,sum[k]++;
		}
	}
	for(ll i=30;i>=0;i--){
		if(sum[i]>=m){
			wh=i;
			break;
		}
	}
	if(wh==-1){
		cout<<0<<"\n";
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(b[i][wh]){
			idx++;
			if(!ans)ans=a[i];
			else ans=ans&a[i];
			if(idx==m)break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
