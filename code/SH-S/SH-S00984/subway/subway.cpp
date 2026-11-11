#include<bits/stdc++.h>
using namespace std;
int n,m,a[3099][3099],c,d,q,p[60000],k[3099],f[3099];
int main(){	  
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=11){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=20000000;
			}
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			int k1;cin>>k1;
			for(int i=1;i<=k1;i++){
				int h,l;
				cin>>h>>l;
				f[i]=h;
//				cout<<f[i]<<'%'<<endl;
				k[f[i]]=l;
			}
			for(int i=1;i<=k1;i++){
				for(int j=1;j<=i;j++){
					a[f[i]][f[j]]=k[f[i]]+k[f[j]];
					a[f[j]][f[i]]=k[f[i]]+k[f[j]];
//					cout<<a[f[j]][f[i]]<<' '<<f[i]<<' '<<f[j]<<endl;
				}
			}
			for(int i;i<=1009;i++){
				f[i]=0;
				k[i]=0;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=i;j++){
				for(int kk=1;kk<=m;kk++){
//					cout<<a[i][j]<<endl;
					a[i][j]=min(a[i][j],a[i][kk]+a[kk][j]);
///					cout<<a[i][j]<<' '<<i<<' '<<j<<endl;
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<a[y][x]+p[x]+p[y]<<endl;
		}
	}
	else{
		
	} 
}
