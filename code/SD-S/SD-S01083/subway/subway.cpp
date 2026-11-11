#include <bits/stdc++.h>
using namespace std;
vector<int> tu[50010];
int station[505];
int n,m,d,q,c,ti[505],k[505],w[50010],m2,k1[50010];
long long dis[50010][510];
void cal(int x){
	for(int i=1;i<=m*d;i++){
		for(int j=1;j<=m*d;j++){
			for(int z=1;z<=m*d;z++){
				dis[i][j%n]=min(dis[i][z%n]+dis[z][j%n]+k1[i],dis[i][j%n]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ti[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		m2+=k[i];
		for(int j=1;j<=k[i];j++){
			int x,y,zx,zy;
			cin>>x>>y;
			k1[n*(station[x]+1)+x]=y;
			for(int o=0;o<station[x];o++){
				tu[o*n+x].push_back((station[x]+1)*n+x);
			}
			station[x]++;
			if(j!=1){
				tu[station[zx]*n+zx].push_back(station[x]*n+x);
				w[n*station[x]+x]=zy;
			}
			zx=x;
			zy=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<station[i];j++){
			for(int z=0;z<tu[j*n+i].size();z++){
				dis[j*n+i][tu[j*n+i][z]%n]=w[tu[j*n+i][z]];
				dis[tu[j*n+i][z]][j*n+i]=w[j*n+i];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<station[i];j++) 
		 cal(i+j*n);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+ti[x]+ti[y]<<"\n";
	}
	return 0;
}
