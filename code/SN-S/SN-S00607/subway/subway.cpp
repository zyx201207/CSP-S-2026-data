#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[500010],e[501][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[i][a]=t;
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		vector<int>v1;
		for(int j=1;j<=n;j++){
			if(e[j][y]!=0){
				v1.push_back(j);
			}
		}
		int dt=1000000000;
		for(int j=0;j<v1.size();j++){
			if(e[v1[j]][x]!=0){
				dt=min(dt,w[x]+e[v1[j]][x]+e[v1[j]][y]+w[y]);
			}
		}
		cout<<dt;
	}
	return 0;
}
