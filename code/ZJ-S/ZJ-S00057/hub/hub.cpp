#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
vector<int>a[20];
bool b[20],f[20];
int d[20];
int dfs(int x){
	f[x]=false;
	int l=a[x].size();
	for(int y=0;y<l;y++)
	    if(f[a[x][y]]==true)
			dfs(a[x][y]);
}
int bfs(int x){
	queue<int>q;
	memset(d,127,sizeof(d));
	d[x]=0;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int l=a[u].size();
		for(int v=0;v<l;v++)
			if(d[a[u][v]]>d[u]+1){
				d[a[u][v]]=d[u]+1;
				q.push(a[u][v]);
			}
	}
	int ma=1e9;
	for(int i=1;i<=n;i++)
	    if(b[i]==true)
			ma=min(ma,d[i]);
	return ma;
}
inline void solve(int x,int cc){
	if(x==n+1){
		if(cc==0){
			int ma=0,sum=0;
			for(int i=1;i<=n;i++)
			    f[i]=b[i];
			for(int i=1;i<=n;i++)
			    if(f[i]==true){
			    	sum++;
			    	dfs(i);
				}     
			if(sum>2)
			    return;  
			for(int i=1;i<=n;i++)
			    ma=max(ma,bfs(i));
			ans=min(ans,ma);
		}
		return;
	}
	if(cc>0){
		b[x]=true;
		solve(x+1,cc-1);
	}
	b[x]=false;
	solve(x+1,cc);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
    	scanf("%d%d",&n,&k);
    	for(int i=1;i<=n;i++)
    	    a[i].clear();
    	for(int i=1;i<n;i++){
    		int u,v;
    		scanf("%d%d",&u,&v);
    		a[u].push_back(v);
    		a[v].push_back(u);
		}
		ans=2e9;
    	memset(b,false,sizeof(b));
		solve(1,k);
		printf("%d\n",ans);
	}
	return 0;
}
