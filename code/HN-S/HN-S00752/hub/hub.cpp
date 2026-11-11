#include<bits/stdc++.h>
using namespace std;
int op,T,n,k,u,v,b[20],d[20],minn,maxn,ff,num;
vector<int>g[1000003];
void pd(int x,int fq){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y!=fq){
			if(b[x]&&b[y]){
				num++;
			}
			pd(y,x);
		}
	}
}
void f(int x,int fq){ 
	d[x]=min(d[x],d[fq]+1);
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y!=fq){
			f(y,x);
			d[y]=min(d[y],d[x]+1);
		}
	}
	if(ff){
		maxn=max(maxn,d[x]);
	}
}
void dfs(int x,int sum){
	if(sum>k){
		return ;
	}
	if(x>n){
		if(sum==k){
			num=0;
			pd(1,0);
			if(k-num>2){
				return ;
			}
			ff=0;
			maxn=0;
			d[0]=1e9;
			for(int i=1;i<=n;i++){
				if(b[i]){
					d[i]=0;
				}else{
					d[i]=1e9;	
				}
			//	cout<<d[i]<<" ";
			}
			//cout<<"\n";
			for(int i=1;i<=n;i++){
				if(b[i]){
					f(i,0);
				}
			}
			ff=1;
			f(1,0);
			minn=min(minn,maxn);	
		}
		return ;
	}
	dfs(x+1,sum);
	b[x]=1;
	dfs(x+1,sum+1);
	b[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>op>>T;
	while(T--){
		minn=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n==k){
			cout<<0<<"\n";
			continue;
		}
		dfs(1,0);
		cout<<minn<<"\n";
	}
	return 0;
} 
