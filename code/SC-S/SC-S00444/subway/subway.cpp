#include<bits/stdc++.h>
#define int long long
#define lop(i,a,b) for(int i=a;i<=b;i++)
#define pol(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int NN=505,MM=5e5+505,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[MM],dis[NN][NN];
vector<pii> to_sub[MM];
void Floyed(){
	lop(k,1,n){
		lop(i,1,n){
			lop(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	lop(i,1,m)cin>>w[i];
	lop(i,1,n){
		int k;cin>>k;
		lop(j,1,k){
			int a,t;cin>>a>>t;
			to_sub[a].pb({i,t});
		}
	}
	mset(dis,0x3f);
	lop(i,1,n)dis[i][i]=0;
	lop(i,1,m){
//		cout<<"size:"<<to_sub[i].size()<<"@\n";
		for(pii u:to_sub[i]){
			for(pii v:to_sub[i]){
				dis[u.fi][v.fi]=min(dis[u.fi][v.fi],u.se+v.se);
			}
		}
	}
//	lop(i,1,n){
//		lop(j,1,n)cout<<dis[i][j]<<" ";
//		cout<<"\n";
//	}
	Floyed();
	while(q--){
		int x,y;cin>>x>>y;
		int ans=INF;
		for(pii u:to_sub[x]){
			for(pii v:to_sub[y]){
				ans=min(ans,u.se+dis[u.fi][v.fi]+v.se);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}