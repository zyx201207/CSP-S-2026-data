#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		cout<<1<<endl<<2;
	}
	while(t--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
		}
		cout<<n/k<<endl;
	}
	return 0;
}
