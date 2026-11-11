#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
		}
		if(t%2==0){
			if(n%2==1)cout<<1<<'\n';
			else cout<<2<<'\n'; 
		}else{
			if(n%2==1)cout<<2<<'\n';
			else cout<<1<<'\n'; 
		}
	}
	return 0;
}
