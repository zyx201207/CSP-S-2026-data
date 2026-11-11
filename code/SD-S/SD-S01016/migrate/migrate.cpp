#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005;
int C,T,a[N],d[N],c[N],n,D,cc[N];
int h[N],e[N],ne[N],idx,vis[N];
struct node{
	int u,w;
};
void add(int u,int v){
	e[++idx]=v,ne[idx]=h[u],h[u]=idx;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>D;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if((a[j]-a[i])<=D) add(i,j);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) d[j]=2e9,c[j]=0,vis[j]=0;
			queue<int> q;
			d[i]=0,q.push(i),c[i]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				for(int j=h[u];j;j=ne[j]){
					int v=e[j];
					if(d[u]+1<d[v]){
						d[v]=d[u]+1;
						c[v]=c[u];
						q.push(v);
					}else if(d[u]+1==d[v]){
						c[v]+=c[u]; 
					}
				
				}
			}
			for(int j=i;j<=n;j++)  ans+=(c[j]==2);
		}
		for(int i=1;i<=n;i++) h[i]=0;
		idx=0;
		cout<<ans<<endl;
	}
	
	return 0;
}

