#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,m,dist[N],head[N],cnt,v[N],maxn;
bool vis[N];
struct awa{
	int to,next;
}e[2*N];
void add(int u,int v){
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
void bfs(int s){
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	queue<int> q;
	q.push(s);
	dist[s]=0;
	vis[s]=1;
	while(!q.empty()){
		int ns=q.front();
		q.pop();
		for(int i=head[ns];i;i=e[i].next){
			int to=e[i].to;
			if(dist[ns]+1<dist[to] && !vis[to]){
				dist[to]=dist[ns]+1;
				vis[to]=1;
				q.push(to);
			}
		}
	}
}
void dfs(int len,int r,int a[],int k){
	if(len==r){
		memset(vis,0,sizeof vis);
		int sum=0;
		for(int i=1;i<=len;i++){
			if(!vis[a[i]]){
				sum++;
				queue<int> q;
				q.push(a[i]);
				vis[a[i]]=1;
				while(!q.empty()){
					int ns=q.front();
					q.pop();
					for(int j=head[ns];j;j=e[j].next){
						int to=e[j].to;
						bool flat=0;
						for(int p=1;p<=len;p++){
							if(a[p]==to){
								flat=1;
								break;
							}
						}
						if(!vis[to] && !flat){
							vis[to]=1;
							q.push(to);
						}
					}
				}
			}
		}
		if(sum<=2){
			int minn=0;
			for(int i=1;i<=len;i++){
				bfs(a[i]);
				for(int j=1;j<=len;j++){
					if(i!=j && vis[a[j]])
						minn=max(minn,dist[a[j]]);
				}
			}
			maxn=min(maxn,minn);
		}
	}
	else{
		for(int i=k;i<=n;i++){
			a[len+1]=i;
			dfs(len+1,r,a,i+1);
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(head,0,sizeof head);
		memset(dist,0x3f,sizeof dist);
		memset(vis,0,sizeof vis);
		cnt=0;
		maxn=1e18;
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		dfs(0,m,v,1);
		cout<<maxn<<endl;
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}
