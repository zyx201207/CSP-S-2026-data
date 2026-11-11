#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
ll a[606][606];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n+m;i++)
		for(int j=1;j<=n+m;j++)
			a[i][j]=2e9;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[m+i][x]=a[x][m+i]=y;
		}
	}
	for(int o=1;o<=n+m;o++)
		for(int i=1;i<=n+m;i++)
			for(int j=1;j<=i;j++){
				if(i==o)continue;
				a[j][i]=a[i][j]=min(a[i][j],a[i][o]+a[o][j]);
			}
//	for(int i=1;i<=n+m;i++){for(int j=1;j<=n+m;j++)cout<<a[i][j]<<" ";cout<<endl;}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<w[x]+w[y]+a[x][y]<<endl;
	}
	return 0;
}
