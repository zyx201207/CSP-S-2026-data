#include<bits/stdc++.h>
using namespace std;
/*====================*/
const int N=1e5+10;
const int M=1e5+10;
/*====================*/
const int INF=0x3f3f3f3f;
const int MOD=998244353;
/*====================*/
int n,k,b[N],dis[N],vis[N];
vector<int> a[N];
int cc;
void dfs(int x,int fa){
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];
		if(y==fa)continue;
		if(dis[x]+1<dis[y])dis[y]=dis[x]+1,dfs(y,x);
	}
}
void dfss(int x,int fa){
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];
		if(b[y]==0)continue;
		if(vis[y])continue;
		vis[y]=1;
		dfss(y,x);
	}
} 
/*====================*/
void Solve(){
	int ans=INF;
	cin>>n>>k;
	for(int i=1;i<=n;i++)a[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			dis[j]=INF;
			vis[j]=0;
			b[j]=(i&(1<<(j-1)));
			if(b[j]>0)b[j]=1;
			cnt+=b[j];
		}
		int cntt=0;
		for(int j=1;j<=n;j++){
			if(b[j]==1&&vis[j]==0){
				vis[j]=1;
				dfss(j,-1);
				cntt++;
			}
		}
		if(cnt!=k||(cntt>2))continue;
		for(int j=1;j<=n;j++){
			if(b[j]==1){
				dis[j]=0;
				dfs(j,-1);
			}
		}
		int maxx=0;
		for(int j=1;j<=n;j++)maxx=max(maxx,dis[j]);
		ans=min(ans,maxx);
	}
	cout<<ans<<'\n';
}
/*====================*/
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>cc;
	int T=1;cin>>T;
	while(T--)Solve();
	return 0;
}


