#include<bits/stdc++.h>
using namespace std;

#define F(i,s,e) for(int i=s;i<=e;i++)
const int N = 50;
int dis[N][N];
int n,k,ans=1e9,c[N];
void work(int i,int cnt){
	if(i==n+1){
		if(cnt==k){
			int sss=0;
			F(i,1,n)
				F(j,1,n)
					if(i!=j&&c[i]&&c[j]&&dis[i][j]==1) sss++;
			if(k-sss>2) return;
			int res=0;
			F(i,1,n){
				if(c[i]) continue;
				int now=1e9;
				F(j,1,n) if(c[j]) now=min(now,dis[j][i]);
//				if(now==0) cout<<i; 
				res=max(res,now);
			}
//			cout<<res<<k;
			ans=min(ans,res);
//			cout<<ans<<'\n';
		}
		return;
	}
	work(i+1,cnt);c[i]=1;work(i+1,cnt+1);c[i]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		memset(dis,0x3f,sizeof dis);
		cin>>n>>k;ans=1e9;
		F(i,1,n) dis[i][i]=0; 
		F(i,1,n-1){
			int u,v;cin>>u>>v;
			dis[u][v]=dis[v][u]=1;
		}
		F(k,1,n)
			F(i,1,n)
				F(j,1,n)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		work(1,0);
		cout<<ans<<'\n';
	}
 	return 0;
} 

