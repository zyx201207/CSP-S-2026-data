#include<bits/stdc++.h>
#define ll long long
#define maxn 5007
using namespace std;
int c,t,n;
ll a[maxn],m;
int dis[maxn][maxn],d[maxn][maxn];
vector<int> p[maxn];
queue<int> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e7;
				d[i][j]=0;
			}
			d[i][i]=1;
			dis[i][i]=0;
			p[i].clear();
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=m) p[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			d[i][i]=1;
			q.push(i);
			int step=0;
			while(!q.empty()){
				step++;
				int l=q.size();
				while(l--){
					int u=q.front();
					q.pop();
					for(auto v:p[u]){
						if(step<dis[i][v]){
							dis[i][v]=step;
							d[i][v]=d[i][u];
							q.push(v);
						}else if(step==dis[i][v]){
							d[i][v]+=d[i][u];
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(d[i][j]==2) ans++; 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}