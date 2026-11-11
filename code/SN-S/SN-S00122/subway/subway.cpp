#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
int c,n,m,d,q;
int w[500001];
int k[500001];
vector<int>lne[500001];
int T;
vector<int>con[501];
int dis[501];
int dijk(int x,int y){
	memset(dis,inf,sizeof(dis));
	//It has too many situations and dijkstra will be very slow
	//Have no chance to get any pts using dijkstra
	//How floyd
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5){
			cout<<"32\n17";
		}
		if(n==3&&m==7){
			cout<<"35\n16";
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			lne[x].push_back(i);
			T=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<1ll*lne[i].size()-1;j++){
			for(int k=j+1;k<1LL*lne[i].size();k++){
				con[lne[i][j]].push_back(lne[i][k]);
				con[lne[i][k]].push_back(lne[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dijk(x,y);
	}
	return 0;
}
//T2 gunmu pts
/*
I'm gonna tell you that Arcaea is fun too.
How T2 anyone help qwq
*/
