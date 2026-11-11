#include<bits/stdc++.h>
using namespace std;
const long long inf=2e18;
int c,n,m,d,Q;
long long s[500100];
struct ww{
	long long a,t;
}a[500100][20];
struct node{
	long long v,w;
};
vector<node>mp[510];
long long p[510][510];
long long ans[510][510];
struct www{
	long long u,v,w;
	bool operator<(const www &x) const{
		return w>x.w;
	}
};
priority_queue<www>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			p[i][j]=inf;
			ans[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t1,t2;
			cin>>t1>>t2;
			a[t1][++a[t1][0].a]={i,t2};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a[i][0].a;j++){
			for(int k=j+1;k<=a[i][0].a;k++){
				if(k!=j){
					p[a[i][j].a][a[i][k].a]=min(a[i][j].t+a[i][k].t,p[a[i][j].a][a[i][k].a]);
					p[a[i][k].a][a[i][j].a]=min(a[i][j].t+a[i][k].t,p[a[i][k].a][a[i][j].a]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(p[i][j]!=inf){
				mp[i].push_back({j,p[i][j]});
				mp[j].push_back({i,p[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		q.push({0,i,0});
		while(!q.empty()){
			www x=q.top();
			q.pop();
			if(x.w<ans[i][x.v]){
				ans[i][x.v]=x.w;
				for(int j=0;j<mp[x.v].size();j++){
					q.push({x.v,mp[x.v][j].v,x.w+mp[x.v][j].w});
				}
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		long long ans1=inf;
		for(int j=1;j<=a[x][0].a;j++){
			for(int k=1;k<=a[y][0].a;k++){
				ans1=min(ans1,ans[a[x][j].a][a[y][k].a]+a[x][j].t+a[y][k].t+s[x]+s[y]);
			}
		}
		cout<<ans1<<"\n";
	}
	return 0;
}
/*


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/



