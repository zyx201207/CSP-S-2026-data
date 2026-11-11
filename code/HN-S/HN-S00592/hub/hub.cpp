#include<bits/stdc++.h>
using namespace std;

int c,t,n,k,u,v;
queue<int> qu[2000005];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			qu[u].push(v);
			qu[v].push(u);
		}
	}
	return 0;
} 
