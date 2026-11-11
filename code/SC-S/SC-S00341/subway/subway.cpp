#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[505][505],t[505][505],z[505][505],f[505][505],k[505];
vector<int> b[505];
int main(){
	//freopen("subway1.in","r",stdin);
	//freopen("subway1.ans","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	vector<int> c[505];
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=k[i];j++){
			if(j==k[i]){
				b[a[i][j]].push_back(a[i][1]);
				b[a[i][1]].push_back(a[i][j]);
				c[a[i][j]].push_back(t[i][1]);
				c[a[i][1]].push_back(t[i][j]);
			}
			else{
				b[a[i][j]].push_back(a[i][j+1]);
				b[a[i][j+1]].push_back(a[i][j]);
				c[a[i][j]].push_back(t[i][j+1]);
				c[a[i][j+1]].push_back(t[i][j]);
			}
		}
	}
	for(int s=1;s<=m;s++){
		queue<int> q;
		vector<int> vis(m+1,0);
		vector<int> time(m+1,-1);
		vis[s]=1;
		z[s][s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<b[u].size();i++){
				int v=b[u][i];
				if(!vis[v]){
					vis[v]=1;
					z[s][v]=z[s][u]+c[u][i];
					q.push(v);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(!b[i][j])continue;
			f[i][j]=w[i]+w[j]+z[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]<<endl;
	}
	return 0;
}