#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
#define F_up(x,y,z) for(int x=y;x<=z;x++)
#define F_down(x,y,z) for(int x=y;x>=z;x--)
#define F_in(x,y) for(auto x:y)
#define W(t) while(t--)
#define WALL while(1)
using namespace std;
int c,t;
int n,m;
int a[2000005];
int dis[5005][5005];
int f[5005][5005];
bool in_queue[2000005];
vector<int> g[5005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	W(t){
		cin>>n>>m;
		F_up(i,1,n){
			cin>>a[i];
		}memset(dis,0x3f3f3f3f,sizeof(dis));
		memset(f,0,sizeof(f));
		F_up(i,1,n){
			g[i].clear();
			F_up(j,1,n){
				if(i==j) continue;
				if(abs(a[i]-a[j])<=m){
					g[i].push_back(j);
				}
			}
		}F_up(i,1,n){
			queue<int> q;
			q.push(i);
			dis[i][i]=0;
			f[i][i]=1;
			memset(in_queue,0,sizeof(in_queue));
			in_queue[i]=1;
			while(!q.empty()){
				int x=q.front();
				q.pop();
				in_queue[x]=0;
				F_in(u,g[x]){
					if(dis[i][u]>dis[i][x]+1){
						dis[i][u]=dis[i][x]+1;
						f[i][u]=f[i][x];
						if(!in_queue[u]){
							in_queue[u]=1;
							q.push(u);
						}
					}else if(dis[i][u]==dis[i][x]+1) f[i][u]+=f[i][x];
				}
			}
		}int ans=0;
		F_up(i,1,n){
			F_up(j,i+1,n){
				if(f[i][j]==2) ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
}