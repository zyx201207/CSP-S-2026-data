#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[125255],k[500005];
int a[25][500005],t[25][500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		int x,y,f1,d1,f2,d2,sum=0;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			for(int u=1;u<=k[j];u++){
				if(a[j][u]==x){
					f1=j;
					d1=u;
				}
				if(a[j][u]==y){
					f2=j;
					d2=u; 
				}
			}
			if(f1==f2){
				for(int j=d1;j<=d2;j++){
					sum+=t[f1][j];
				}
			}
		}
		cout<<sum+w[x]+w[y]<<"\n";
	}
}
