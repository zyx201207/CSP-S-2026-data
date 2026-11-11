#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;
ll C,T,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(ll i=1;i<=n-1;i++){
            ll u,v;
            cin>>u>>v;
        }
        if(n==k) cout<<0<<'\n';
        else cout<<1<<'\n';
    }
	return 0;
}
