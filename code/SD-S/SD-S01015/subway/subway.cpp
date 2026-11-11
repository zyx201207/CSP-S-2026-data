#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct line{
	int id,w;
};
vector<int> s[501];
int a[20010][501];
int num[501]; 
vector<int> j[50001];
int dis[5001][501];
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		cin>>num[i];dis[i][i]=0;
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i][x]=y;
			s[i].push_back(x);
			for(auto w:s[i]){
				dis[w][x]=min(dis[w][x],a[i][x]+a[i][w]);
				dis[x][w]=dis[w][x];
			}
		}
	}
for(int k=1;k<=m;k++){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			dis[j][i]=dis[i][j];
		} 
	}
}
while(q--){
	int x,y;
	cin>>x>>y;
	cout<<dis[x][y]+num[x]+num[y]<<endl;
}
	return 0;
}


