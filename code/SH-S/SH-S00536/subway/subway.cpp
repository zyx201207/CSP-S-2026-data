#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
vector<int> s[N];
vector<ll> t[N];
/*
n 地铁线路数
m 地铁站数
d 每个地铁站最多被几条线路经过
q 出行计划数
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<vector<ll>> dis(m+1,vector<ll>(m+1,0x3f3f3f3f));
	vector<ll> w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){ 
		int x,a;
		ll b;
		cin>>x;
		for(int j=1;j<=x;j++){ 
			cin>>a>>b;
			s[i].push_back(a); 
			t[i].push_back(b);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i].size();j++){
			for(int k=j+1;k<s[i].size();k++){
				dis[s[i][j]][s[i][k]]=min(dis[s[i][j]][s[i][k]],t[i][j]+t[i][k]);
				dis[s[i][k]][s[i][j]]=min(dis[s[i][k]][s[i][j]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}		
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
}

