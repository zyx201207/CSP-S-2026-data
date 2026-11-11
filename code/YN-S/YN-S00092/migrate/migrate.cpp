#include<bits/stdc++.h>
using namespace std;

const int scx=1e5+10;
int c,t;
int n,d;
int x[scx];
int a[15][15][100];
bool vis[20];
int ans;

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<10){
		ans=0;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			queue<pair<int,int> >q;
			q.push(make_pair(i,0));
			memset(vis,false,sizeof vis);
			while(!q.empty()){
				int u=q.front().first;
				int op=q.front().second;
				q.pop();
				if(vis[u])continue;
				vis[u]=true;
				for(int i=u+1;i<=n;i++){
					if(x[i]-x[u]<=d){
						q.push(make_pair(i,op+1));
						a[u][i][op+1]++;
					}else{
						break;
					}
				}
				for(int i=u-1;i>=1;i--){
					if(x[u]-x[i]<=d){
						q.push(make_pair(i,op+1));
						a[u][i][op+1]++;
					}else{
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				for(int d=1;;d++){
					if(a[i][j][d]==2){
						ans++;
						
					}
					else if(a[i][j][d]==0)continue;
					else break;
				}
			}
		}
		cout<<ans<<'\n';
	}else{
		cout<<0<<"\n";
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
