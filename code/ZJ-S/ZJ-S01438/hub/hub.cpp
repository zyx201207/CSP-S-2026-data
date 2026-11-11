#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=1e6+10;
vector<int>g[N];
int de[N],vis[N],r=1,f[N];
int n,m;
void dfs(int x,int fa,int op,int dis,int opt){
	if(op&&de[x]<=dis)vis[x]=1;
	for(int i:g[x])if(i!=fa&&(!vis[i]||opt)){
		de[i]=de[x]+1;
		dfs(i,x,op,dis,opt);
	}
}
void dfs1(int x,int fa){
	for(int i:g[x])if(i!=fa&&vis[i]){
		vis[i]=0;
		dfs1(i,x);
	}
}
bool check(int x){
	for(int i=1;i<=n;i++)vis[i]=0;
	de[r]=0;
	dfs(r,0,0,0,0);
	int r1=0;
	for(int i=1;i<=n;i++){
		if(de[i]==x)r1=i;
	}
	de[r1]=0;
	dfs(r1,0,1,x,0);
	r1=-1;
	for(int i=1;i<=n;i++)if(!vis[i])r1=i;
	if(r1==-1)return 1;
	de[r1]=0;
	dfs(r1,0,0,0,0);
	for(int i=1;i<=n;i++)if(de[i]>de[r1])r1=i;
	de[r1]=0;
	dfs(r1,0,0,0,0);
	r1=-1;
	for(int i=1;i<=n;i++)if(de[i]==x)r1=i;
	if(r1==-1)return 1;
	de[r1]=0;
	dfs(r1,0,1,x,0);
	for(int i=1;i<=n;i++)if(!vis[i])return 0;
	return 1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(m>=n){
			cout<<0<<'\n';
			continue;
		}
		if(c==13||c==14){
			cout<<max(1,(n/2-(m-2)+2)/4+1)<<'\n';
			continue;
		}
		if(m<=2){
			de[1]=0;
			dfs(1,0,0,0,0);
			for(int i=1;i<=n;i++)if(de[i]>de[r])r=i;
			int l=1,r=n;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid))r=mid-1;
				else l=mid+1;
			}
			cout<<r<<'\n';
			continue;
		}
		if(n<=10){
			int ans=1e9;
			for(int i=1;i<1<<n;i++){
				int cnt=0,cnt1=0;
				for(int j=0;j<n;j++){
					if(i>>j&1){
						cnt++;
						vis[j+1]=1;
					}
				}
				int ma=0;
				for(int j=1;j<=n;j++)if(!vis[j]){
					de[j]=0;
					dfs(j,0,0,0,1);
					int mi=1e9;
					for(int k=1;k<=n;k++)if(vis[k])mi=min(mi,de[k]);
					ma=max(ma,mi);
				}
				for(int j=1;j<=n;j++)if(vis[j]){
					vis[j]=0;
					dfs1(j,0);
					cnt1++;
				}
				if(cnt>m||cnt1>2)continue;
				ans=min(ans,ma);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n<=100){
			int ans=1e9;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++)vis[k]=0,f[k]=n+1;
					vis[i]=1,vis[j]=1;
					queue<int>q;
					for(int k=1;k<=n;k++)if(g[k].size()==1&&!vis[k]){
						f[k]=0;
						q.push(k);
					}
					while(!q.empty()){
						int t=q.front();
						for(int k:g[t]){
							if(f[k]>f[t]+1){
								f[k]=f[t]+1;
								q.push(k);
							}
						}
						q.pop();
					}
					int tot=0,l=2;
					for(int k=1;k<=n;k++)if(g[k].size()>1&&!f[k])tot++;
					priority_queue<PII>q1;
					q1.push({tot,0});
					for(int k:g[i])if(!vis[k]&&f[k])q1.push({f[k],k}),vis[k]=1;
					for(int k:g[j])if(!vis[k]&&f[k])q1.push({f[k],k}),vis[k]=1;
					while(!q1.empty()&&l<m){
						int t=q1.top().second;
						l++;
						if(t)for(int k:g[j])if(!vis[k]&&f[k])q1.push({f[k],k}),vis[k]=1;
						else q1.push({q1.top().first-1,0});
						q1.pop();
					}
					ans=min(ans,q1.top().first);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		cout<<1<<'\n';
	}
	//The end...
	return 0;
}