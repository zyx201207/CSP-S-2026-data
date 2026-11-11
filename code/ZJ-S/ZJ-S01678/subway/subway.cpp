#include<bits/stdc++.h>
using namespace std;
int c,n,m;
int d,q;
int w[500005],k[500005];
int t[500005][45],a[500005][45];
bool vis[500005];
int bfs(int x,int y){
	queue<int>q;
	queue<int>qd;
	q.push(x);
	qd.push(0);
	while(!q.empty()){
		int nx=q.front(),nd=qd.front();
		q.pop();
		qd.pop();
		if(nx==y){
			return nd;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==nx&&!vis[i]){
					vis[i]=1;
					for(int x=1;x<=k[i];x++){
						if(a[i][x]!=nx){
						    q.push(a[i][x]);
						    qd.push(nd+t[i][x]+t[i][j]);
						} 
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m;
	cin>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		cout<<bfs(x,y)+w[x]+w[y]<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
