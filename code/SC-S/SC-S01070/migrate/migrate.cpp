#include<bits/stdc++.h>
#define int long long
using namespace std;
int cc,t,n,d,g[5005][5005],a[100005],dis[100005],c[100005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++) g[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d) ++g[i][0],g[i][g[i][0]]=j;
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[j]=1e9,c[j]=0;
			queue<pair<int,int>> q;q.push({i,0});
			dis[i]=0,c[i]=1;
			while(!q.empty()){
				int u=q.front().first,t=q.front().second;q.pop();
				for(int j=1;j<=g[u][0];j++){
					int v=g[u][j];
					if(t+1<dis[v]) c[v]=c[u],dis[v]=t+1,q.push({v,t+1});
					else if(t+1==dis[v]) c[v]+=c[u];
				}
			}
			int cnt=0;
			for(int j=i;j<=n;j++)
				if(c[j]==2) cnt++;
			res+=cnt; 
		}
		cout<<res<<endl;
	}
	return 0;
}