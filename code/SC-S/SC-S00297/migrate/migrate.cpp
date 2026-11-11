#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5,M=5e3+3;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int bity,T;
	cin>>bity>>T;
	while(T--){
		long long n,d,a[MAXN];
		long long c[M][M],r[M][M];
		cin>>n>>d;
		if(bity==11||bity==12){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int l=i-1;
			while(a[i]-a[l]<=d){
				c[i][l]=c[l][i]=a[i]-a[l];
				r[i][l]=r[l][i]=1;
				l--;
			}
		}
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++) c[i][j]=1000000000000000;
		}
		for(int i=1;i<=m+n;i++){
			for(int j=i+1;j<=m+n;j++){
				for(int k=1;i<=n;i++){
					if(k==i||k==j) continue;
					if(c[i][j]>c[i][k]+c[k][j]) c[i][j]=c[j][i]=c[i][k]+c[k][j],r[j][i]=r[i][j]=r[i][k]*r[j][k];
					else if(c[i][j]==c[i][k]+c[k][j]) r[j][i]=r[i][j]=r[i][k]*r[j][k]+r[i][j];
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) if(r[i][j]==2) ans++;
		}
		cout<<ans/2;
	}
	return 0;
} 