#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200010],dp[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
		ll maxn=0;
		for(int i=1;i<(1<<n);i++){
			if(__builtin_popcount(i)!=m) continue;
			ll ans=2147483647;
			for(int j=0;j<n;j++){
				if(i&(1<<j)) ans&=a[j+1];
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		ll ans=0;
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		ll maxn=-1;
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}
	if(m==2){
		ll ans=-1;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if(a[n]<=4){
		ll cnt3,cnt2,cnt1;
		for(int i=1;i<=n;i++){
			if(a[i]==3) cnt3++;
			if(a[i]==2) cnt2++;
			if(a[i]==1) cnt1++;
		}
		if(cnt3+cnt2>=m) cout<<2;
		else if(cnt3+cnt1>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	ll ans=0;
	for(int i=n;i>=n-m+1;i--) ans&=a[i];
	cout<<ans;
	return 0;
}
