#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000010;
int c,T,n,k,fa[N],cnt,a[N],ans=2e9,dis[N];
int f1[N],f2[N],dp[N];
vector<int>p[N];
void dfs1(int x,int father){
	fa[x]=father;
	for(int y:p[x]){
		if(y==father)continue;
		dfs1(y,x);
	}
}
queue<int>q;
bool vis[N];
void dfs(int now){
	if(cnt>k||cnt+n-now+1<k)return;
	if(now>n){
		for(int i=1;i<=cnt;i++)vis[a[i]]=1;
		int S=cnt;
		for(int i=1;i<=cnt;i++)if(vis[fa[a[i]]])--S;
		for(int i=1;i<=cnt;i++)vis[a[i]]=0;
		if(S<=2){
			int res=0;
			for(int i=1;i<=n;i++)dis[i]=2e9;
			for(int i=1;i<=cnt;i++)q.push(a[i]),dis[a[i]]=0;
			while(!q.empty()){
				int x=q.front();q.pop();
				res=max(res,dis[x]);
				for(int y:p[x])if(dis[y]==2e9)dis[y]=dis[x]+1,q.push(y);
			}
			ans=min(ans,res);
		}
		return;
	}
	a[++cnt]=now,dfs(now+1);
	--cnt,dfs(now+1);
}
void Dfs(int x,int father,int C){
	f1[x]=f2[x]=dp[x]=0;
	for(int y:p[x]){
		if(y==father)continue;
		Dfs(y,x,C),dp[x]+=dp[y];
		if(f1[y]+1>f1[x])f2[x]=f1[x],f1[x]=f1[y]+1;
		else if(f1[y]+1>f2[x])f2[x]=f1[y]+1;
	}
	if(f1[x]+f2[x]>C)++dp[x],f1[x]=0;
}
void clear(){
	for(int i=1;i<=n;i++)fa[i]=0,p[i].clear();
	ans=2e9;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			p[u].push_back(v),p[v].push_back(u);
		}
		if(n<=10)dfs1(1,0),dfs(1);
		else{
			int l=0,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				Dfs(1,0,mid);
				if(dp[1]<=k)ans=mid,r=mid-1;
				else l=mid+1;
			}
		}
		cout<<ans<<'\n';
		clear();
	}
	return 0;
}
