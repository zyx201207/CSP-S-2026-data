#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=400;
int i,j,k,res,n,d,T,c,mi,now;
int x[N],dis[N],vis[N],ans[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;res=0;
		for(i=1;i<=n;i++) cin>>x[i];
		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++) dis[i]=1e9,vis[i]=0,ans[i]=0;
			dis[k]=0;ans[k]=1;
			for(i=1;i<=n;i++){
				mi=1e9;now=0;
				for(j=1;j<=n;j++)
					if(!vis[j]&&dis[j]<mi) mi=dis[j],now=j; 
				for(j=1;j<=n;j++)
					if(vis[j]&&abs(x[now]-x[j])<=d&&dis[j]+1==mi)
						ans[now]+=ans[j];
				if(ans[now]==2) res++;
				vis[now]=1;
				for(j=1;j<=n;j++)
					if(!vis[j]&&abs(x[now]-x[j])<=d)
						dis[j]=min(dis[j],mi+1);
			}	
		}
		cout<<res/2<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
