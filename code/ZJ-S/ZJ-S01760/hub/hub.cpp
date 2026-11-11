#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int main(){
	freopen("r","hub.in",stdin);
	freopen("w","hub.out",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
	}
	n/=2;
	n-=m-2;
	cout<<(n+2)/3;
}
