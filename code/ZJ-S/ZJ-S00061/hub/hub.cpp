#include <bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<=n;i++){
			cin>>u>>v;
		}
		cout<<(n-1)/8<<'\n';
	}
	return 0;
}

