#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int N=1e6+10,M=1e3+10,MOD=1e9+7;

int main(){
	fastio;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cout<<rand()%(2*N)<<'\n';
	}
	return 0;
}
