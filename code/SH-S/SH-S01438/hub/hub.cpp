#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,fa[500005],u,v,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		m=n/2;
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		if(k>=m){
			cout<<1<<'\n';
			continue;
		}
		if(k==1){
			cout<<m/2+1<<'\n';
			continue;
		}
		cout<<(m-k-1)/4+2<<'\n';
	}
	return 0;
}
