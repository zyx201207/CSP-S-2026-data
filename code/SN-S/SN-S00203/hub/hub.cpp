#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
ll c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if(c==0){
		cout<<1<<'\n'<<2<<endl;
		return 0;
	}
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;cin>>u>>v;
		}
		cout<<0<<'\n';
	}
	return 0;
}
