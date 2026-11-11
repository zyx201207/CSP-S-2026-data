#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	ll m;
	cin>>n>>m;
	vector<ll> b(n); 
	for(ll i=0;i<n;i++){
		cin>>b[i];
	}
	sort(b.begin(),b.end());
	ll k=(b.front()+b.back())/2;
	for(ll i=(b.front()+b.back())/2;;k/=2){
		vector<ll> t;
		for(ll j=0;j<n;j++){
			if(b[j]<=i){
				t.push_back(b[j]);
			}
		}
		ll tmp=i*t.size()-accumulate(t.begin(),t.end(),0ll);
		if(k<1)k=1;
		if(tmp>m){
			
			vector<ll> t2;
			for(ll j=0;j<n;j++){
				if(b[j]<=i-1){
					t2.push_back(b[j]);
				}
			}
			ll tmp2=(i-1)*t2.size()-accumulate(t2.begin(),t2.end(),0ll);
			
			cout<<i-1<<' '<<tmp2<<'\n';
			if(tmp2<=m){
				cout<<t2.size();
				break;
			}
			
			i-=k;
		}else if(tmp<m){
			
			i+=k;

		}else if(tmp==m){
			cout<<t.size();
			break;
		}
		
	}
	return 0;
}