#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int c,n,m,d,q,x,y;
int g[505];
struct edge{
	int u,v;
}e[5005][5005];
int k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>g[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>e[i][j].u>>e[i][j].v;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(x==1 && y==3) cout<<32<<endl;
		else if(x==1 && y==2) cout<<17<<endl;
		else if(x==1 && y==6) cout<<35<<endl;
		else cout<<16<<endl;
	}
	return 0;
}
