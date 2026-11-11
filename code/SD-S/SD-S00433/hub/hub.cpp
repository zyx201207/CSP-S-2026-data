#include <bits/stdc++.h>

using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(q--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<(n-k)/3+1<<"\n";
	}
	return 0;
}
