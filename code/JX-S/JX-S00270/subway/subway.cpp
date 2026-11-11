#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e5+5,T=1005;
int o,n,m,d,q,k;
int e[T],ne[T],w[T],h[N],idx;
long long c[T];
long long dist[T];
int p[T];
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
long long dijkstra(int sr,int ed){
	memset(dist,0x3f,sizeof dist);
	int tt=0,hh=0;
	p[tt++]=sr;
	dist[sr]=0;
	while(hh<tt){
		int t=p[hh++];
		for(int i=h[t];~i;i=ne[i]){
			int j=e[i];
			if(dist[j]>dist[t]+w[i]){
				dist[j]=dist[t]+w[i];
				p[tt++]=j;
			}
		}
	}
	return dist[ed];
}	
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(h,-1,sizeof h);
    cin>>o>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
		cin>>k;
		int a,b,c,d;
		if(k==1)cin>>a>>b;
		else cin>>a>>b>>c>>d;
		add(a,c,b+d);
		add(c,a,b+d);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)+c[x]+c[y]<<"\n";
	}
    return 0;
}

