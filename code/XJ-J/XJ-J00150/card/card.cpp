#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>p;
vector<ll>cnt(3000000,0);
ll wz(vector<ll>a,ll x){
	ll ans=-1;
	for(ll i=0;i<a.size();i++){
		if(a[i]==x){
			ans=i;
			break;
		}
	}
	return ans;
}
void sc(vector<ll>&a,ll x){
	for(ll i=x;i<a.size();i++){
		a[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll t;
		cin>>t;
		p.push_back(t);
	}
	for(ll i=0;i<n;i++){
		vector<ll>z;
		for(ll j=i;j<n;j++){
			ll w=wz(z,p[j]);
			if(w==-1){
				z.push_back(p[j]);
			}
			else{
				sc(z,w);
				z.push_back(p[j]);
			}
			/*cout<<w<<endl;
			for(ll k=0;k<z.size();k++){
				cout<<z[k]<<" ";
			}
			cout<<endl;*/
		}
		for(ll j=1;j<=m;j++){
			if(wz(z,j)!=-1){
				cnt[j]++;
			}
		}
		
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
