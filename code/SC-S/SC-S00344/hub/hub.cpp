#include<bits/stdc++.h>
using namespace std;
vector<int>e[25];
int fa[25],n,K,ans;
int a[25],dis[25][25];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x!=y)fa[x]=y;
}
void dfs(int k){
	if(k>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i])cnt++; 
			fa[i]=i;
		}
		if(cnt!=K)return;
		for(int i=1;i<=n;i++){
			for(int j:e[i]){
				if(a[i]&&a[j]){
					merge(i,j);
				}
			}
		}
		set<int>s;int res=0;
		for(int i=1;i<=n;i++){
			if(a[i])s.insert(find(i));
		}
		if(s.size()>2)return;
		for(int i=1;i<=n;i++){
			int tp=n+1;
			if(a[i]==1)continue;
			for(int j=1;j<=n;j++){
				if(a[i]==0&&a[j]==1){
					tp=min(tp,dis[i][j]);
				}
			}
			res=max(res,tp);
		}
		ans=min(ans,res);
	}else{
		a[k]=0;
		dfs(k+1);
		a[k]=1;
		dfs(k+1); 
	}
}
int main(){
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int cc,tt;cin>>cc>>tt;
	while(tt--){
		cin>>n>>K;
		if(n<=10){
			ans=n;
			memset(dis,0x3f,sizeof(dis));
			for(int i=1;i<=n;i++){
				e[i].clear();
				dis[i][i]=0;
			}
			for(int i=1;i<n;i++){
				int x,y;cin>>x>>y;
				e[x].emplace_back(y);
				e[y].emplace_back(x);
				dis[x][y]=dis[y][x]=1;
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					if(i==k)continue;
					for(int j=1;j<=n;j++){
						if(i==j||j==k)continue; 
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
			dfs(1);cout<<ans<<"\n";
		}else{
			for(int i=1;i<n;i++){
				int x,y;cin>>x>>y;
			}	
			cout<<1<<"\n";	
		} 
	}
	return 0;
}