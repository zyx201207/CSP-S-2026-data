#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505];
const long long MAX=1e18;
struct node{
	int id;
	long long d;
};
long long dis[505][505];
vector<node> sta[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)dis[i][j]=MAX;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long a,b;
			cin>>a>>b;
			sta[a].push_back({i,b});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<sta[i].size();j++){
			for(int k=0;k<sta[i].size();k++){
				if(j==k)continue;
				node l1=sta[i][j],l2=sta[i][k];
				long long htime=l1.d+l2.d;
				dis[l1.id][l2.id]=min(dis[l1.id][l2.id],htime);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)continue;
			for(int j=1;j<=n;j++){
				if(i==j||k==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=0;i<sta[x].size();i++){
			for(int j=0;j<sta[y].size();j++){
				int l1=sta[x][i].id,l2=sta[y][j].id;
				long long ndis=dis[l1][l2]+sta[x][i].d+sta[y][j].d+w[x]+w[y];
				ans=min(ans,ndis);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
