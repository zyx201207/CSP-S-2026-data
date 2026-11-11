#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],ans=1;
ll s[500005];//²î¾à 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		s[i]=a[n]-a[i];
	}for(ll i=n;i>=1;i--){
		ll nz=m;
		ll cnt=1;
		for(ll j=i-1;j>=1;j--){
			if(nz-s[j]+s[i]>=0){
				nz=nz-s[j]+s[i];
				cnt++;
			}else{
				break;
			}
		}ans=max(ans,cnt);
	}cout<<ans;
	return 0;
}
