#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][500005],t[505][500005]; 
int vis[500005];
struct pp{
	int x;int st;int p;
};
int bfs(int l,int r){
	queue<pp>q;
	vis[l]=1;
	q.push({l,0,-1});
	while(q.empty()){
		pp nm=q.front();
		vis[nm].x++;
		q.pop();
		for(int i=1;i<=n;i++){
			
		}
	}
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<bfs(l,r);
	}
	return 0;
}