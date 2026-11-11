#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,ans,T,c,n,d,a[200010],dis1[200010],dis2[200010],vis[200010][4],dis3[200010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
vector<int>f[200010];
void dij(int x){
	int fx,i,fy,j,sx,sg1,sg2,sg3;
	memset(vis,0,sizeof(vis));
	memset(dis1,127,sizeof(dis1));
	memset(dis2,127,sizeof(dis2));
	memset(dis3,127,sizeof(dis3));
	dis1[x]=a[x];q.push({0,x});
	while(!q.empty()){
		fx=q.top().second;
		fy=dis1[fx];
		q.pop();
		if(vis[fx][1]==0)vis[fx][1]=1;
		else if(vis[fx][2]==0)vis[fx][2]=1;
		else if(vis[fx][3])continue;
		else vis[fx][3]=1;
		
		for(i=0;i<f[fx].size();i++){
			sx=f[fx][i];sg1=dis1[fx]+1;
			sg2=dis2[fx]+1;
			sg3=dis3[fx]+1;
			if(vis[fx][2]==0)
				if(sg1<dis1[sx]){
					dis3[sx]=dis2[sx];
					dis2[sx]=dis1[sx];
					dis1[sx]=sg1;q.push({sg1,sx});
				}
				else if(sg1<dis2[sx]){
					dis3[sx]=dis2[sx];
					dis2[sx]=sg1,q.push({sg1,sx});
				}
				else if(sg1<dis3[sx]){
					dis3[sx]=sg1;q.push({sg1,sx});
				}
			if(vis[fx][3]==0)
				if(sg2<dis1[sx]){
					dis3[sx]=dis2[sx];
					dis2[sx]=dis1[sx];
					dis1[sx]=sg2;q.push({sg2,sx});
				}
				else if(sg2<dis2[sx]){
					dis3[sx]=dis2[sx];
					dis2[sx]=sg2,q.push({sg2,sx});
				}
				else if(sg1<dis3[sx]){
					dis3[sx]=sg2;q.push({sg2,sx});
				}
			if(sg3<dis3[sx]){
				dis3[sx]=sg3;q.push({sg3,sx});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(abs(a[j]-a[i])<=d)f[i].push_back(j),f[j].push_back(i);
		for(i=1;i<=n;i++){
			dij(i);
			for(j=i+1;j<=n;j++)
				if(dis2[j]==dis1[j]&&dis2[j]!=dis3[j])
					ans++;			
		}
		for(i=1;i<=n;i++)f[i].clear();
		cout<<ans<<"\n";ans=0;
	}
}
