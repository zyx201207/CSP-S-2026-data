#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q1,w[N],k,nm,t[510][N],T,l,r,mn=1e9;
vector<vector<int> >vis(N),a(N);
queue<int>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>nm>>t[i][j];
			T=t[i][j];
			for(int x=0;x<vis[nm].size();x++){
				int y=vis[nm][x];
				a[i].push_back(y);
				a[y].push_back(i);
			}
			vis[nm].push_back(i);
		}
	}
	for(int i=1;i<=q1;i++){
		cin>>l>>r;
		vector<bool>vis2(N);
		vector<int>dist(N,1e9);
		mn=1e9;
		for(int f=0;f<vis[l].size();f++){
			int e=vis[l][f];
			q.push(e);
			dist[e]=0;
			while(!q.empty()){
				int x=q.front();
				q.pop();
				if(vis2[x])continue;
				vis2[x]=1;
				for(int y=0;y<a[x].size();y++){
					int z=a[x][y];
					if(dist[z]>dist[x]+1){
						dist[z]=dist[x]+1;
						q.push(z);
					}
				}
			}
			for(int j=0;j<vis[r].size();j++){
				int x=vis[r][j];
				mn=min(mn,dist[x]);
			}
		}
		cout<<mn*T*2+2*T+w[l]+w[r]<<'\n';
	}
	return 0;
}