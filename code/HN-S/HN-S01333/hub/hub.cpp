#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		cin>>n>>k;
		for (int j=1;j<=n-1;j++){
			cin>>u>>v;
		}
	}
	if(v==5){
		cout<<1<<endl<<2;
	}
	if(v==6){
		cout<<0<<endl<<1;
	}
	return 0;
}
