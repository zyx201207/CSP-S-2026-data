#include<iostream>
using namespace std;
int c,t,n,f[305][305];
long long d,x[305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					f[i][j]=1;
				}else{
					f[i][j]=1e9;
				}
			}
		}
		for(int l=2;l<=n;l++){
			for(int i=1;i<=n-l+1;i++){
				int cnt=0,j=i+l-1;
				for(int k=i+1;k<j;k++){
					if(f[i][k]+f[k][j]==f[i][j]){
						cnt++;
					}
					if(f[i][k]+f[k][j]<f[i][j]){
						f[i][j]=f[i][k]+f[k][j];
						cnt=1;
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}