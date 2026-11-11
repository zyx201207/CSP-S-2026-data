#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int c,t,n,k,u,v,f[2000010],dis[2000010],tt=1e9;
vector<int>tr[1000010];
queue<int>qq;
void dfs(int m,int p,int q){
	if(p==k){
		//cout<<p+q+1<<" ";
		//for(int i=1;i<=n;i++)cout<<f[i]<<" ";
		//cout<<endl; 
		int ans=0;
		for(int i=1;i<=n;i++){
			dis[i]=1e9;
			if(f[i]==1)qq.push(i),dis[i]=0;
		}
		while(qq.size()){
			int u=qq.front();
			qq.pop();
			ans=max(ans,dis[u]);
			for(int i=0;i<tr[u].size();i++){
				int v=tr[u][i];
				if(dis[v]>n){
					dis[v]=dis[u]+1;
					qq.push(v);
				}
			}
		}
		tt=min(tt,ans);
	}else{
		int t=0,a=p+q+1;
		for(int j=0;j<tr[a].size()&&!t;j++)if(f[j]==1)t=1;
		//cout<<p+q+1<<" "<<p<<" "<<q<<" "<<t<<endl;
		if(t){
			f[a]=1;
			dfs(m,p+1,q);
			f[a]=0;
		}else if(m<2){
			f[a]=1;
			dfs(m+1,p+1,q);
			f[a]=0;
		}
		if(q<n-k){
			f[a]=2;
			dfs(m,p,q+1);
			f[a]=0;
		}
	}
}
int main(){
	freopen("hub1.in","r",stdin);
	freopen("hub1.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			tr[u].push_back(v);
			tr[v].push_back(u);
		}
		dfs(0,0,0);
		printf("%d\n",tt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
