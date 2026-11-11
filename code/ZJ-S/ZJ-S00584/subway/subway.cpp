#include<bits/stdc++.h>//T2->subway
using namespace std;
const int N=9117;
int n,m;
long long d,q,a[N],dis[N][N];
struct line{
	long long sta;//sta->station
	long long a[N],w[N];
}l[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		for(int j=i+1;j<=m;j++){
			dis[i][j]=INT_MAX;
			dis[j][i]=INT_MAX;
		}
	}for(int i=1;i<=n;i++){
		cin>>l[i].sta;
		for(int j=0;j<l[i].sta;j++){
			cin>>l[i].a[j]>>l[i].w[j];
		}for(int j=0;j+1<l[i].sta;j++){
			for(int k=j+1;k<l[i].sta;k++){
				long long num=l[i].w[j]+l[i].w[k];
				dis[l[i].a[j]][l[i].a[k]]=min(num,dis[l[i].a[j]][l[i].a[k]]);
				dis[l[i].a[k]][l[i].a[j]]=min(num,dis[l[i].a[k]][l[i].a[j]]);
			}
		}
	}
	bool flag=1;
	while(flag){
		flag=0;
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				for(int k=1;k<=m;k++){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
						flag=1;
					}
				}
			}
		}
	}while(q--){
		long long x,y,ret=0;
		cin>>x>>y;
		ret=a[x]+a[y]+dis[x][y];
		cout<<ret<<endl;
	}
	return 0;
}
