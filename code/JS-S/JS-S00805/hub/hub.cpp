#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int c,t,n,k,fa[N],e[N][2],dis[N][N],ans,cnt;
int find(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
void add(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	++cnt;
	fa[x]=y;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=105;
		for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)dis[i][j]=dis[j][i]=105;
		for(int i=1;i<n;++i)cin>>e[i][0]>>e[i][1],dis[e[i][0]][e[i][1]]=dis[e[i][1]][e[i][0]]=1;
		for(int i=0;i<(1<<n);++i){
			if(__builtin_popcount(i)!=k)continue;
			for(int i=1;i<=n;++i)fa[i]=i;
			cnt=0;
			for(int j=1;j<n;++j){
				if(i&(1<<(e[j][0]-1))&&(i&(1<<(e[j][1]-1)))){
					add(e[j][0],e[j][1]);
				}
			}
			if(cnt>=k-2){
				for(int d=1;d<=n;++d){
					for(int l=1;l<=n;++l){
						for(int r=1;r<=n;++r)dis[l][r]=min(dis[l][r],dis[l][d]+dis[d][r]);
					}
				}
				int sum=0;
				for(int u=1;u<=n;++u){
					int dd=105;
					for(int v=1;v<=n;++v){
						if(i&(1<<(v-1))){
							dd=min(dd,dis[u][v]);
						}
					}
					sum=max(sum,dd);
				}
				ans=min(ans,sum);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
