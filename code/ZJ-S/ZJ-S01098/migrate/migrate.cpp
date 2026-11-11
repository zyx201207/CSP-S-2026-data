#include <bits/stdc++.h>
#define int long long
using namespace std;
int x,n,d,T,l,i,j,fx,fb,sx,sb,sum,ans[500010],a[500010],dis[500010];
vector<int> f[500010],g[500010];
queue<int> q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>x>>T;
	while(T--){
		cin>>n>>d;sum=0;
		for(i=1;i<=n;i++) cin>>a[i],f[i].clear();
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)
					f[i].push_back(j);
		for(i=1;i<=n;i++){
			memset(dis,127,sizeof(dis));
			memset(ans,0,sizeof(ans));
			q.push(i);dis[i]=0;
			while(!q.empty()){
				fx=q.front();
				fb=dis[fx];
				q.pop();
				for(j=0;j<f[fx].size();j++){
					sx=f[fx][j];
					sb=fb+1;
					if(sb<=dis[sx]){
						if(sb==dis[sx]) ans[sx]++;
						else ans[sx]=1;
						dis[sx]=sb;
						q.push(sx);
					}
				}
			}
			for(j=i+1;j<=n;j++)
				if(ans[j]==2)
					sum++;
		}
		cout<<sum<<"\n";
	}
}
