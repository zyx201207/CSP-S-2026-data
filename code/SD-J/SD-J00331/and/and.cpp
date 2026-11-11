#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
vector<ll> v;
ll n,m;
ll ma=-1;
void gh(ll k,ll c){
	if(k==n&&c!=m){
		return ;
	}
	if(c==m){
		ll oi=v[0];
		for(ll i=1;i<m;i++){
			oi=oi&v[i];
			//cout<<oi<<"/";
		}
		ma=max(ma,oi);
		
		//cout<<oi<<":";
		//for(ll i=0;i<v.size();i++){
		//	cout<<v[i]<<" ";
		//}
		//cout<<endl;
		
		return ;
	}
	for(ll i=k+1;i<=n;i++){
		v.push_back(a[i]);
		gh(i,c+1);
		v.pop_back();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		v.push_back(a[i]);
		gh(i,1);
		v.pop_back();
	}
	cout<<ma;
	return 0;
}
