#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int w[M];
struct S{
	int b,t;
};
vector<S> v[M];
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int b=1;b<=n;b++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
			cin>>a>>t;
			v[a].push_back({b,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int a=1;a<=m;a++){
		for(S s1:v[a]){
			for(S s2:v[a]){
				dis[s1.b][s2.b]=min(dis[s1.b][s2.b],(long long)s1.t+s2.t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long mn=1e18;
		for(S s1:v[x]){
			for(S s2:v[y]){
				mn=min(mn,dis[s1.b][s2.b]+s1.t+s2.t);
			}
		}
		cout<<mn+w[x]+w[y]<<'\n';
	}
	return 0;
}
