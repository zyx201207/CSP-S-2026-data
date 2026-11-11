#include<bits/stdc++.h>
using namespace std;
int n,k;
int to[2000005],nxt[2000005],head[2000005],cnt=0;
void add(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(;t-->0;){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
	}
	return 0;
}
