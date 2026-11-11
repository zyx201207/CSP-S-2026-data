#include <bits/stdc++.h>
using namespace std;
constexpr int N=1000005;
using ll=long long;
int n,k;
ll m[N],mm[N];
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int c,t;cin>>c>>t;
    while(t--){
    	cin>>n>>k;
    	for(int i=1;i<n;++i)cin>>m[i]>>mm[i];
    	ll ans=(n-1)/2;
    	ans=(ans-1)/2;
    	ans=(ans-k/2)/2+2;
    	cout<<ans<<'\n';
	}
	return 0;
} 

