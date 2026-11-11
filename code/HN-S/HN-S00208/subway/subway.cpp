#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct sam{
	long long s,t;
};
long long c,n,m,d,q,t[1005],a[1005][1005];
vector<sam> v[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=0x3f;
		}
	}
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y>>z;
			v[i].push_back({y,z});
		}
	}
	for(int i=1;i<=n;i++){
		int k=v[i].size();
		for(int j=0;j<k;j++){
			for(int l=1;l<k;l++){
				a[v[i][j].s][v[i][l].s]=v[i][j].t+v[i][l].t;
				a[v[i][l].s][v[i][j].s]=v[i][j].t+v[i][l].t;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int l=1;l<=m;l++){
				if(a[i][j]>a[i][l]+a[l][j]){
					a[i][j]=a[i][l]+a[l][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<t[x]+t[y]+a[x][y]<<"\n";
	}
	return 0;
}

