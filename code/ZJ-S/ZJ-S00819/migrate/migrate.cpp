#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,d,i,j,fx,s,t,fl,ma,sx,x[2000010],vis[2000010],dis[2000010],ans[2000010];
vector<int>f[2000010];
priority_queue<pair<int,int> >q;
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T>>T;
	while(T--){
		cin>>n>>d;s=0;
		for(i=1;i<=n;i++)f[i].clear();
		for(i=1;i<=n;i++)cin>>x[i];
		t=x[2]-x[1];fl=1;
		for(i=3;i<=n;i++)
			if(x[i]-x[i-1]!=t)fl=0;
		if(fl){
			if(n-1<d/t||d<=t)cout<<0<<"\n";
			else{
				ma=2*(d/t)-1;
				cout<<n-1-(ma)+1<<"\n";
			}
			continue;
		}
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				if(abs(x[j]-x[i])<=d){
					f[i].push_back(j);
					f[j].push_back(i);
				}
		for(i=1;i<n;i++){
			for(j=1;j<=n;j++)vis[j]=0,dis[j]=1e18,ans[j]=0;
			q.push(make_pair(0,i));dis[i]=0;ans[i]=1;
			while(!q.empty()){
				fx=q.top().second;
				q.pop();
				if(vis[fx])continue;
				vis[fx]=1;
				for(j=0;j<f[fx].size();j++){
					sx=f[fx][j];
					if(dis[sx]>dis[fx]+1){
						dis[sx]=dis[fx]+1;
						ans[sx]=ans[fx];
						q.push(make_pair(-dis[sx],sx));
					}
					else if(dis[sx]==dis[fx]+1){
						ans[sx]++;
					}
				}
			}
			for(j=i+1;j<=n;j++)
				if(j!=i&&ans[j]==2)s++;
		}
		cout<<s<<"\n";
	}
	return 0;
}