#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,cnt=0,head[1000010],dept[1000010],dept2[1000010],maxdep=0,flag=0;
struct node{
	int nxt;
	int from;
	int to;
}edge[2000010];
void add(int u,int v){
	edge[++cnt].nxt=head[u];
	head[u]=cnt;
	edge[cnt].from=u;
	edge[cnt].to=v;
	return;
}
int maxx(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int ans[2][5010];
void dfs(int C,int u,int father,int dep){
	ans[C][dept[u]]++;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==father){
			continue;
		}
		if(i==flag||i==(flag+1)){
			continue;
		}
		dfs(C,v,u,dep+1);
	}
}
void treedp1(int C,int root,int u,int father,int dep){
	int child=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==father){
			continue;
		}
		if(i==flag||i==(flag+1)){
			continue;
		}
		dept[v]=dep+1;
		treedp1(C,root,v,u,dep+1);
		dept[u]=maxx(dept[u],dept[v]+1);
		child++;
	}
	if(child==0){
		dept[u]=0;
	}
}
int minn(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
signed main(){
	freopen("hub2.in","r",stdin);
	//freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		cnt=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		int anss=10000;
		for(int i=1;i<n;i++){
			for(int j=0;j<=4000;j++){
				ans[0][j]=ans[1][j]=0;
			}
			flag=i*2-1;
			int x=edge[flag].from,y=edge[flag].to;
			maxdep=0;
			treedp1(0,x,x,0,0);
			dfs(0,x,0,0);
			maxdep=0;
			treedp1(1,y,y,0,0);
			dfs(1,y,0,0);
			for(int j=n;j>=0;j--){
			ans[0][j]=ans[0][j+1]+ans[0][j];
			ans[1][j]=ans[1][j+1]+ans[1][j];
			}
			for(int j=0;j<=n;j++){
				if(ans[0][j]+ans[1][j]<=k){
					anss=min(anss,j);
				}
			}
		}
		cout<<anss<<endl;
		
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}
