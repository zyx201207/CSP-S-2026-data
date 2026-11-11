#include<bits/stdc++.h>
#define open(x) string fn=x;freopen((fn+".in").c_str(),"r",stdin);freopen((fn+".out").c_str(),"w",stdout);
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(s) s.begin(),s.end()
#define endl '\n'
using namespace std;
using ll=long long;

signed main(){
	open("and");
	io;
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n+5,0);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll answer=0;
	ll k=pow(2,n)-1;
	for(ll i=1;i<=k;i++){
		ll ans=0;
		ll ls=i;
		ll j=1;
		ll c=0;
		while(ls){
			if(c>m){
				break;
			}
			if(ls%2==1){
				if(ans==0)ans=a[j];
				else ans&=a[j];
				c++;
			}
			ls>>=1;
			j++;
		}
		if(c==m) answer=max(ans,answer);
	}
	cout<<answer<<endl;
	return 0;
}

