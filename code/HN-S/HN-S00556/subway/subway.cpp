#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[500005],k,x,y,t[505][500005],vis[500005];

void spfa(int s,int t){
	queue<int> qu;
	memset(vis,0,sizeof(vis));
	qu.push(s);
	vis[s]=1;
	
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			t[i][a]=b;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		spfa(x,y);
	}
	return 0;
}
