#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
int w[N];//每个地铁站的地铁口走到站厅需要的时间
int k[N];
int a[200][500005];
int t[200][500005];
int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;//m个地铁站 n条线路 q个出行计划每个地铁站最多有d个线路通过 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(abs(x-y)==1){
			cout<<w[x]+w[y]+t[i][x]+t[i][y];
			return 0;
		}
		int ans=0;
		for(int j=x;j<=y;j++){
			ans+=t[i][j];
		}
		cout<<w[x]+w[y]+ans;
		
		
	}
	return 0;
} 
