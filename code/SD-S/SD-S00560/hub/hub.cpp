#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define pb push_back
#define pii pair<ll,ll>
#define p_q priority_queue
#define mk make_pair
#define endl '\n'
#define fi first
#define se second
#define lowbit(x) ((x)&(-x))
#define INF 0x3f3f3f3f
namespace cute_fzj_kuai_ruarua{
	int c;
	int n,k;
	ve<int>tr[1000005];
	int dis[4005][4005];
	void get(int x,int fa,int rt){
		for(auto y:tr[x]){
			if(y==fa) continue;
			dis[rt][y]=dis[rt][x]+1;
			get(y,x,rt);
		}
	}
	int f[4005][4005];
	int mx[4005];
	int siz[4005],dfn[4005],tot=0;
	int tmp[4005];
	void dp(int x,int fa){
		siz[x]=1;
		dfn[x]=++tot;
		for(auto y:tr[x]){
			if(y==fa) continue;
			dp(y,x);
			mx[x]=max(mx[x],mx[y]+1);
		}
		f[x][1]=0;
		for(auto y:tr[x]){
			if(y==fa) continue;
			for(int i=1;i<=n;i++){
				tmp[i]=INF;
			}
			for(int i=1;i<=siz[x];i++){
				for(int j=1;j<=siz[y];j++){
					tmp[i+j]=min(tmp[i+j],max(f[x][i],f[y][j]));
				}
			}
			for(int i=2;i<=n;i++){
				f[x][i]=min(max(f[x][i],mx[y]+1),tmp[i]);
			}
			f[x][1]=max(f[x][1],mx[y]+1);
			siz[x]+=siz[y];
		}
		if(siz[x]==1) f[x][1]=0;
	}
	void solve(){
		cin>>n>>k;
		for(int i=1;i<=n;i++) tr[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			tr[x].pb(y);
			tr[y].pb(x);
		}
		if(c<=6&&n<=100){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				get(i,0,i);
			}
			int ans=INF;
			for(int rt=1;rt<=n;rt++){
				tot=0;
				for(int i=1;i<=n;i++){
					for(int j=0;j<=n;j++){
						f[i][j]=INF;
						mx[i]=0;
						siz[i]=0;
					}
				}
				dp(rt,0);
				ans=min(ans,f[rt][k]);
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(dfn[i]<=dfn[j]&&dfn[j]<=dfn[i]+siz[i]-1) continue;
						if(dfn[j]<=dfn[i]&&dfn[i]<=dfn[j]+siz[j]-1) continue;
						int mx=0;
						for(int k_=1;k_<=n;k_++){
							if(dfn[i]<=dfn[k_]&&dfn[k_]<=dfn[i]+siz[i]-1) continue;
							if(dfn[j]<=dfn[k_]&&dfn[k_]<=dfn[j]+siz[j]-1) continue;
							mx=max(mx,min(dis[k_][i],dis[k_][j]));
						}
						for(int k_=1;k_<k;k_++){
							ans=min(ans,max(mx,max(f[i][k_],f[j][k-k_])));
						}
					}
				}
			}
			cout<<ans<<endl;
			return ;
		}
		int m=(n-1)/2;
		m+=2;
		if(k==n){
			cout<<0<<endl;
			return ;
		}
		if(k>=m){
			cout<<1<<endl;
		}
		int ans=(m-k+1)/2;
		int l=1,r=m,pos=m;
		while(l<=r){
			int mid=(l+r)/2;
			int val=(mid-1)*2+1;
			if(k>=m-val-mid*2){
				pos=mid;
				r=mid-1;
			}else l=mid+1;
		}
		cout<<min(pos,ans)<<endl;
	}
	void main(){
		int T;
		cin>>c>>T;
		while(T--) solve();
	}
}
using namespace cute_fzj_kuai_ruarua;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cute_fzj_kuai_ruarua::main();
	return 0;
}

