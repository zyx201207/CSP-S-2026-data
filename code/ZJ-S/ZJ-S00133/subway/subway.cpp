#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,o[500010],p[510][510];
vector<int> n[500010],m[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>a>>b>>c>>d;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			p[i][j]=1000000000000;
		}
		p[i][i]=0;
	}
	for(int i=1;i<=b;i++){
		cin>>o[i];
	}
	for(int i=1;i<=a;i++){
		int x,y,z;
		cin>>x;
		while(x--){
			cin>>y>>z;
			n[y].push_back(i);
			m[y].push_back(z);
		}
	}
	for(int i=1;i<=b;i++){
		for(int j=0;j<n[i].size();j++){
			for(int k=j+1;k<n[i].size();k++){
				p[n[i][j]][n[i][k]]=p[n[i][k]][n[i][j]]=min(p[n[i][j]][n[i][k]],m[i][j]+m[i][k]);
			}
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			for(int k=1;k<=a;k++){
				p[j][k]=min(p[j][i]+p[i][k],p[j][k]);
			}
		}
	}
	while(d--){
		int x,y;
		cin>>x>>y;
		int mi=1000000000000;
		for(int i=0;i<n[x].size();i++){
			for(int j=0;j<n[y].size();j++){
				mi=min(mi,p[n[x][i]][n[y][j]]+m[x][i]+m[y][j]);
			}
		}
		cout<<mi+o[x]+o[y]<<'\n';
	}
	return 0;
}
