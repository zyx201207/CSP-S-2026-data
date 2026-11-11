#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,tmp,sum=0;char ctmp;cin>>n;
	if(n==1){cout<<0;return 0;}
	vector<pair<char,ll>> v;
	for(int i=1;i<=n;i++){
		cin>>tmp>>ctmp;
		sum+=tmp;
		v.push_back(make_pair(ctmp,tmp));
	}
	if(sum<=1e7){
		ll l=1,r=sum,lp=0,rp=v.size()-1,sl=0,sr=0;
		ll ans=0;
		for(l;l<=r;l++){
			if(v[lp].fi!=v[rp].fi) ans++;
			sl++;sr++;
			if(sl>=v[lp].se){sl=0;lp++;}
			if(sr>=v[rp].se){sr=0;rp--;}
			r--;
		}
		cout<<ans;
		return 0;
	}
	else{
		ll lp=0,rp=v.size()-1;
		ll ans=0;
		while(lp<rp){
			ll nd=min(v[lp].se,v[rp].se);
			if(v[lp].fi==v[rp].fi){
				if(v[lp].se==v[rp].se){
					lp++;rp--;
				}
				else if(v[lp].se>v[rp].se){
					v[lp].se-=v[rp].se;
					rp--;
				}
				else{
					v[rp].se-=v[lp].se;
					lp++;
				}
			}
			else{
				if(v[lp].se==v[rp].se){
					ans+=v[lp].se;
					lp++;rp--;
				}
				else if(v[lp].se>v[rp].se){
					ans+=v[rp].se;
					v[lp].se-=v[rp].se;
					rp--;
				}
				else{
					ans+=v[lp].se;
					v[rp].se-=v[lp].se;
					lp++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
