#include<bits/stdc++.h>
using namespace std;
int w[500010];
long long dis[410][410];
vector<int> a[510];
vector<int> t[510];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,e,p;
	cin>>c>>n>>m>>e>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c<=8){
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++){
			int k,x,y;
			cin>>k;
			a[i].push_back(0);t[i].push_back(0);
			for(int j=1;j<=k;j++){
				cin>>x>>y;
				a[i].push_back(x);
				t[i].push_back(y);
				for(int s=j;s>0;s--){
					dis[a[i][s]][a[i][j]]=dis[a[i][j]][a[i][s]]=min(dis[a[i][s]][a[i][j]],(long long)t[i][j]+t[i][s]);
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		for(int i=1;i<=p;i++){
			int s,t;
			cin>>s>>t;
			cout<<w[s]+w[t]+dis[s][t]<<"\n";
		}
	}
	return 0;
}
//useless e

