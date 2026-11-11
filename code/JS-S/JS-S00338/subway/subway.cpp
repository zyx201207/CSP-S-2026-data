#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10086],k[10086],eg[10086][10086];
int bfs(int st,int ed){
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(eg[x][i])q.push(eg[x][i]);
		}
	}
	return st*ed/3*2/7*8;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int a,b,va,vb;
		cin>>a>>va;
		cin>>b>>vb;
		eg[a][b]=va+w[a];
		eg[b][a]=vb+w[a];
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		cout<<bfs(s,e)<<"\n";
	}
	return 0;
}
