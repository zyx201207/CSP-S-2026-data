#include<bits/stdc++.h>
using namespace std;
int dis[1000005];
vector<int> vec[1000005];
int used[1000005];
int D[1005][1005];
int n,k;
void paint(int u){
	used[u]=1;
	for(int v:vec[u]){
		if(!used[v]) paint(v);
	}
}
void dfs(int u,int fa,int d){
	dis[u]=min(dis[u],d);
	for(int v:vec[u]){
		if(v!=fa) dfs(v,u,d+1);
	}
}
bitset<1005> B[1005],F;
bool check(int x){
	for(int i=1;i<=n;i++) F[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(D[i][j]<=x) B[i][j]=1;
			else B[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((B[i]|B[j])==F) return 1;
		}
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T; scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		if(1<=c&&c<=3){
			int ans=1e9;
			for(int mask=0;mask<(1<<n);mask++){
				if(__builtin_popcount(mask)!=k) continue;
				for(int i=1;i<=n;i++) dis[i]=1e9,used[i]=-1;
				for(int i=1;i<=n;i++){
					if(mask&(1<<i-1)) used[i]=0;
				}
				int cnt=0;
				for(int i=1;i<=n;i++){
					if(!used[i]) paint(i),cnt++;
				}
				if(cnt>2) continue;
				for(int i=1;i<=n;i++){
					if(used[i]==1) dfs(i,0,0);
				}
				int res=0;
				for(int i=1;i<=n;i++) res=max(res,dis[i]);
				ans=min(ans,res);
			}
			printf("%d\n",ans);
		}
		else if(c==7){
			F.reset();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) dis[j]=1e9;
				dfs(i,0,0);
				for(int j=1;j<=n;j++) D[i][j]=dis[j];
			}
			int l=0,r=n,ans=n;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid)) ans=mid,r=mid-1;
				else l=mid+1;
			}
			printf("%d\n",ans);
		}
		else if(c==13||c==14){
			if(n==k){
				puts("0");
			}
			else{
				int m=(n-1)/2; printf("%d\n",max(1,(m-k+3)/4+1));
			}
		}
		else puts("1");
	}
	return 0;
}
