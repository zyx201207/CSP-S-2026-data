#include<bits/stdc++.h>
#define N 500001
using namespace std;
int m,n,c,d,a[N],t[N],ques,w[N],f[N],g[N];
bool l[N];
int nxt[N],cnt,h[N];
pair<int,int>e[N];
queue<int>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>ques;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
			for(int j=1;j<i;j++){
				nxt[++cnt]=h[a[i]];
				h[a[i]]=cnt;
				e[cnt]={a[j],t[i]+t[j]};
				nxt[++cnt]=h[a[j]];
				h[a[j]]=cnt;
				e[cnt]={a[i],t[i]+t[j]};
			}
		}
	}while(ques--){
		int x,y;
		cin>>x>>y;
		memset(f,0x3f,sizeof f);
		memset(g,0x3f,sizeof g);
		memset(l,0,sizeof l);
		f[x]=g[x]=0;
		q.push(x);
		while(!q.empty()){
			int x=q.front();
			q.pop();
			l[x]=0;
			if(g[x]==d)continue;
			for(int i=h[x];i;i=nxt[i]){
				int u=e[i].first,v=e[i].second;
				if(f[u]>f[x]+v){
					f[u]=f[x]+v;
					g[u]=g[x]+1;
					if(!l[u])q.push(u);
					l[u]=1;
				}else if(f[u]==f[x]+v&&g[u]>g[x]+1){
					g[u]=g[x]+1;
					if(!l[u])q.push(u);
					l[u]=1;
				}
			}
		}cout<<f[y]+w[x]+w[y]<<"\n";
	}return 0;
}
