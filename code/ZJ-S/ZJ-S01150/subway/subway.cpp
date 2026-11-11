#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[250000],k[505],num[500005][25][2],idx[505];
long long dist[505][505];
vector<long long>a[505],t[505];
bool op=true;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof(dist));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		dist[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2){
			op=false;
		}
		for(int j=0;j<k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			num[x][++idx[x]][0]=i;
			num[x][idx[x]][1]=j;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=idx[i];j++){
			for(int l=0;l<k[j];l++){
				dist[i][a[num[i][j][0]][l]]=min(dist[i][a[num[i][j][0]][l]],t[num[i][j][0]][num[i][j][1]]+t[num[i][j][0]][l]);
			}
		}
	}
	while(--n){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int l=1;l<=m;l++){
					dist[i][j]=min(min(dist[i][j],dist[j][i]),dist[i][l]+dist[l][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dist[x][y]<<'\n';
	}
	return 0;
}