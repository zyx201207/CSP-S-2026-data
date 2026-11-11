#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,k,i,j,mi;
int u[1100000],v[1100000],b[11];
int f[11][11];
vector<int> F[11];
void qiu(){
	int fx,sx,i,j,ma=0;
	int vis[11],dis[11],d[11];
	queue<int> q;
	memset(d,63,sizeof(d));
	for(i=1;i<=k;i++){
		q.push(b[i]);
		memset(dis,63,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[b[i]]=0;
		vis[b[i]]=1;
		while(!q.empty()){
			fx=q.front();
			q.pop();
			for(j=0;j<F[fx].size();j++){
				sx=F[fx][j];
				if(dis[fx]+1<dis[sx]){
					dis[sx]=dis[fx]+1;
					if(!vis[sx]){
						vis[sx]=1;
						q.push(sx);
					}
				}
			}
		}
		for(j=1;j<=n;j++) d[j]=min(d[j],dis[j]);
	}
	for(i=1;i<=n;i++) ma=max(ma,d[i]);
	mi=min(mi,ma);
}
void dfs(int x,int cnt,int ltk){
	int fl=1,i;
	if(x==n+1){
		if(ltk<=2&&cnt==k) qiu();
		return;
	}
	if(cnt>k||ltk>2) return;
	dfs(x+1,cnt,ltk);
	for(i=1;i<=cnt;i++){
		if(f[x][b[i]]){
			fl=0;
			break;
		}
	}
	b[cnt+1]=x;
	dfs(x+1,cnt+1,ltk+fl);
}
bool A(){
	int i,m;
	if(n%2==0) return 0;
	m=(n-1)/2;
	for(i=1;i<=m;i++){
		if(u[i]!=i||v[i]!=i+1) return 0;
	}
	for(i=m+1;i<=n-1;i++){
		if(u[i]!=i-m&&v[i]!=i+1) return 0;
	}
	return 1;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
    	cin>>n>>k;
    	for(i=1;i<=n-1;i++) cin>>u[i]>>v[i];
    	if(n<=10){
    		mi=1e18;
    		for(i=1;i<=n;i++) F[i].clear();
    		for(i=1;i<=n;i++) for(j=1;j<=n;j++) f[i][j]=0;
    		for(i=1;i<=n-1;i++){
    			f[u[i]][v[i]]=1;
    			f[v[i]][u[i]]=1;
    			F[u[i]].push_back(v[i]);
    			F[v[i]].push_back(u[i]);
			}
    		dfs(1,0,0);
    		cout<<mi<<"\n";
		}
		else if(A()){
			if(((n-1)/2+2-k)%4==0) cout<<((n-1)/2+2-k)/4<<"\n";
			else cout<<((n-1)/2+2-k)/4+1<<"\n";
		}
		else cout<<n/2<<"\n";
	}
}