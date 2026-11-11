#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
int dot,T,n,k,u,v,f[5001][5001],fa[N];
vector<int>e,edge[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void unin(int u,int v){
	int fu=find(u),fv=find(v);
	if(fu!=fv){
		fa[fu]=fv;
	}
}
int one(int x){
	int res=0;
	while(x){
		res+=x&1;
		x>>=1;
	}
	return res;
}
void pri(int x){
	for(int i=1;i<=n;i++){
		cout<<(1&(x>>(i-1)))<<' ';
	}
	cout<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>dot>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			edge[i].clear();
			for(int j=1;j<=n;j++){
				f[i][j]=1e9;
			}
			f[i][i]=0;
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			edge[u].push_back(v);
			f[u][v]=f[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		int ans=1e9,p=0;
		for(int i=1;i<(1<<n);i++){
			if(one(i)!=k)continue;
			e.clear();
			for(int j=1;j<=n;j++){
				fa[j]=j;
				if(((i>>(j-1))&1)==0)continue;
				e.push_back(j);
			}
			for(auto u:e){
				for(auto v:edge[u]){
					if(((i>>(v-1))&1)==0)continue;
					unin(u,v);
				}
			}
			int tot=0;
			for(auto tt:e){
				if(find(tt)==tt)tot++;
			}
			if(tot>2)continue;
			int maxn=0;
			for(int j=1;j<=n;j++){
				if(((i>>(j-1))&1)==1)continue;
				int minn=1e9;
				for(auto to:e){
					minn=min(minn,f[j][to]);
				}
				maxn=max(maxn,minn);
			}
			if(maxn<ans)ans=maxn,p=i;
			
		}
		//pri(p);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/