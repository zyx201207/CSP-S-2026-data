#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005,M=5e5+5;
int c,n,m,d,q; 
int t[M];
struct node{
	int t;
	int p; 
};
vector<node> l[M];
int dis[N][N]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i]; 
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int p,t;
			cin>>p>>t;
			l[p].push_back({t,i});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dis[i][j]=LONG_LONG_MAX/2;
		}
		for(int j=i+1;j<=n;j++){
			dis[i][j]=LONG_LONG_MAX/2;
		}
	}
	for(int i=1;i<=m;i++)
		for(node p1:l[i])
			for(node p2:l[i])
				dis[p1.p][p2.p]=min(p1.t+p2.t,dis[p1.p][p2.p]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		int mn=LONG_LONG_MAX;
		for(node p1:l[a]){
			for(node p2:l[b]){
				mn=min(t[a]+t[b]+p1.t+p2.t+dis[p1.p][p2.p],mn);
			}
		}
		cout<<mn<<'\n';
	}
	return 0;
}

