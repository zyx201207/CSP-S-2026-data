#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[505][505],dk[505][25],df[505][500005],w[500005];
int main(){
	freopen("subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int az,bz,cz;
	for(int i=1;i<=n;i++){
		cin>>az;
		for(int j=1;j<=az;j++){
			cin>>bz>>cz;
			int dz=dk[i][0];
			dz++;
			dk[i][dz]=bz;
			df[i][bz]=cz;
			dk[i][0]=dz;
		}
	}
	for(int i=1;i<=n;i++){
		a[i][i]=0;
		for(int j=1;j<=n;j++){
			a[i][j]=INT_MAX/2-1;
			for(int k=1;k<=dk[i][0];k++){
				if(df[j][dk[i][k]]!=0){
					a[i][j]=min(a[i][j],df[j][dk[i][k]]+df[i][dk[i][k]]);
				}
				a[j][i]=a[i][j];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	int x,y,ans;
	for(int i=1;i<=q;i++){
		cin>>x>>y;ans=INT_MAX/2-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(df[i][x]&&df[j][y]){
					ans=min(ans,a[i][j]+w[i]+w[j]+df[i][x]+df[j][y]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
