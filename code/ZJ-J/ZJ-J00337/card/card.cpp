#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500010];
vector<ll> b[300010];
ll q[300010];
ll T[300010];
ll p[300010];
bool flag;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]].push_back(i);
	}
	
	for(ll i=1;i<=m;i++){
		ll cnt=0;
		for(ll i=1;i<=m;i++){
			p[i]=0;
		}
		for(ll j=1;j<=n;j++){
			b[a[j]][++p[j]]=j;
		}
		for(ll j=1;j<=n;j++){
			bool fp=0;
			ll ops=0;
			for(ll k=1;k<j;k++){
				if(a[k]==a[j]){
					fp=1;
					ops=k;
					break;
				}
			}
			if(fp==0){
				cnt++;
				continue;
			}
			for(ll p=ops+1;p<=j;p++){
				a[p]=1e9;
			}
			for(auto c:b[a[i]]){
				if(c<ops){
					cnt++;
					fp=1;
					break;
				}
			}
			if(fp){
				continue;
			}
			
		}
		cout<<cnt<<' ';
	}	
	return 0;
}