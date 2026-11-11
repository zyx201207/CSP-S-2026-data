#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
int w[500005];
struct bian{
	int v,time;
	bian(int _v=0,int _time=0):v(_v),time(_time){
		return;
	}
};
vector<bian> xian[505];
vector<bian> zhan[500005];
vector<bian> mp[505];
int ddis[505][505];

void bbuild(){
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<xian[i].size();j++){
			for(int l = 0;l<zhan[xian[i][j].v].size();l++){
				mp[i].push_back(bian(zhan[xian[i][j].v][l].v,
					xian[i][j].time+zhan[xian[i][j].v][l].time));
			}
		}
	}
	return;
}
void ffloyd(){
	for(int i = 1;i<=n;i++)ddis[i][i]=0;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<mp[i].size();j++){
			ddis[i][mp[i][j].v]=min(ddis[i][mp[i][j].v],mp[i][j].time);
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				ddis[i][j]=min(ddis[i][j],ddis[i][k]+ddis[k][j]);
			}
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;cin >> k;
		for(int j = 1;j<=k;j++){
			int a,tt;cin >> a >> tt;
			xian[i].push_back(bian(a,tt));
			zhan[a].push_back(bian(i,tt));
		}
	}
	memset(ddis,0x3f,sizeof(ddis));
	bbuild();
//	for(int i = 1;i<=n;i++){
//		for(int j = 0;j<mp[i].size();j++){
//			cout << "(" << mp[i][j].v << " " << mp[i][j].time << ")  ";
//		}cout << endl;
//	}
	ffloyd();
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout << ddis[i][j] << " "; 
//		}
//		cout << endl;
//	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int ans = 0x3f3f3f3f3f3f3f3f;
		if(x==y){
			cout << 0 << endl;
			continue; 
		}
		for(int i = 0;i<zhan[x].size();i++){
			for(int j = 0;j<zhan[y].size();j++){
				ans=min(ans,
					ddis[zhan[x][i].v][zhan[y][j].v]+
					zhan[x][i].time+zhan[y][j].time+
					w[x]+w[y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

