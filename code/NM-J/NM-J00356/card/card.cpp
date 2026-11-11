#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll sz[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	ll n,m;
	cin>>n>>m;
	
	for(ll i=1;i<=n;++i){
		cin>>sz[i];
	}
	
	for(ll i=1;i<=m;++i){
		cout<<n<<' ';
	}
	
	return 0;
}
