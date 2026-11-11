#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n=0,d=0,x[20005],b[5005][5005],bb[5005][5005],f[5005][5005],ans=0;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
//		vector<long long>a[200005];
		n=0;d=0;ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=1e9;
				bb[i][j]=0;
			}
			b[i][i]=0;
			f[i][i]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<d){
					b[i][j]=1;
					b[j][i]=1;
//					a[i].push_back(j);
//					a[j].push_back(i);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(b[i][j]>b[i][k]+b[k][j]){
						b[i][j]=b[i][k]+b[k][j];
						f[i][j]=f[i][k]^f[k][j];
					}
				}	
			}
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				for(int k=1;k<=n;k++){
					if(b[i][j]==b[i][k]+b[k][j]&&i!=j){
						bb[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(bb[i][j]==4){
					ans++;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(b[i][j]==1e9){
//					cout<<"N ";
//				}
//				else{
//					cout<<b[i][j]<<' ';
//				}
//			}
//			cout<<'\n';
//		}
		cout<<ans/2<<'\n';
	}
	return 0;
}

