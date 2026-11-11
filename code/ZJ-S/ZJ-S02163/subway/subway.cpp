#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e9;
int c,n,m,d,q;
int w[500005];
int a[3][500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	if(c==21||c==22){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=0;i<2;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=MAXN;
			}
		}
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			while(k--){
				int x;
				cin>>x;
				cin>>a[i][x];
			}
		}
		int minn=4e9;
		for(int i=1;i<=m;i++) minn=min(minn,a[0][i]+a[1][i]);
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			int ans=4e9;
			ans=min(min(min(a[0][x]+a[0][y],a[1][x]+a[1][y]),a[1][x]+a[0][y]+minn),a[0][x]+a[1][y]+minn);
			cout<<ans+w[x]+w[y]<<endl;
		}
		return 0;
	}
	int k[5][15];
	for(int i=0;i<n;i++){
		cin>>k[i][0];
		for(int j=1;j<=k[i][0];j++){
			int x;
			cin>>x;
			cin>>k[i][x];
		}
	}
	int m0_1=4e9,m0_2=4e9,m1_2=4e9;
	for(int i=1;i<=m;i++){
		m0_1=min(m0_1,k[0][i]+k[1][i]);
		m0_2=min(m0_1,k[0][i]+k[2][i]);
		m1_2=min(m0_1,k[1][i]+k[2][i]);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=4e9;
		ans=min(ans,k[0][x]+k[0][y]);
		ans=min(ans,k[0][x]+k[0][y]);
		ans=min(ans,k[0][x]+k[0][y]);
		ans=min(ans,k[0][x]+k[1][y]+m0_1);
		ans=min(ans,k[0][x]+k[2][y]+m0_2);
		ans=min(ans,k[1][x]+k[2][y]+m1_2);
		ans=min(ans,k[0][x]+k[1][y]+m0_2+m1_2);
		ans=min(ans,k[0][x]+k[2][y]+m0_1+m1_2);
		ans=min(ans,k[1][x]+k[2][y]+m0_1+m0_2);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
