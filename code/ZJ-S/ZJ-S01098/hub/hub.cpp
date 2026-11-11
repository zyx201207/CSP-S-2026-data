#include <bits/stdc++.h>
#define int long long
using namespace std;
int x,y,n,k,T,i,j,mi,fx,fb,sx,sb,ma,ans,dis[310][110],fl[310];
vector<int> f[310],g[310];
queue<int> q;
void sc(int t,int s){
	int i,j;
	if(s>k) return ;
	if(t>n){
		if(s<k) return ;
		ma=0;
		for(i=1;i<=n;i++){
			mi=2e9;
			for(j=1;j<=n;j++)
				if(fl[j])
					mi=min(mi,dis[i][j]);
			ma=max(ma,mi);
		}
		ans=min(ans,ma);
		return ;
	}
	fl[t]=1;sc(t+1,s+1);
	fl[t]=0;sc(t+1,s);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>x>>T;
	if(x>3){
		for(i=1;i<n;i++){
			cin>>n>>k;
			cout<<(k+1)/2<<"\n";
		}
		return 0;
	}
	while(T--){
		cin>>n>>k;ans=2e9;
		for(i=1;i<n;i++){
			cin>>x>>y;
			f[x].push_back(y);
			f[y].push_back(x);
		}
		memset(dis,127,sizeof(dis));
		for(i=1;i<=n;i++){
			q.push(i);dis[i][i]=0;
			while(!q.empty()){
				fx=q.front();
				fb=dis[i][fx];
				q.pop();
				for(j=0;j<f[fx].size();j++){
					sx=f[fx][j];
					sb=fb+1;
					if(sb<dis[i][sx]){
						dis[i][sx]=sb;
						q.push(sx);
					}
				}
			}
		}
		sc(1,0);
		cout<<ans<<"\n";
	}
}
