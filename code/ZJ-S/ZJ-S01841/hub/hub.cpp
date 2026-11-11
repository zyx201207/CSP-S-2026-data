#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,a[20010][20010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u][v]=1;
			a[v][u]=1;
		}
	}
	return 0;
}