#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;
ll a[500010],b[500010];
ll cnt[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		if(i==1) b[i]=abs(a[i]-0);
		else b[i]=a[i]-a[i-1];
	}
	ll mxf=-1;
	for(ll i=1;i<n;i++){
		for(ll j=i+1;j<=n;j++){
			ll cnt=0,flag=j-i+1;
			for(ll k=i;k<=j;k++){
				cnt+=b[k]*(k-i+1);
			}
			ll cnt2=b[j]*(j-i+1);
			if(cnt>m&&cnt-cnt2<m){
				mxf=max(mxf,flag-1);
			}else if(cnt==m){
				mxf=max(mxf,flag);
			}
		}
	}
	cout<<mxf+1;
	return 0;
} 
