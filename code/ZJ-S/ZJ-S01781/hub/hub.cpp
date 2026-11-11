#include<bits/stdc++.h>
using namespace std;
int c,t,fa[1000005];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		int n,k;
		cin>>n>>k;
		if(k==2){
			
		}
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			fa[find(u)]=find(v);
		}
		for(int i=1;i)
	}
	return 0;
}
