#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,d,sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		n=0,d=0,sum=0;
		cin>>n>>d;
		long long int a[n+1],f[n+1][n+1],minn[n+1][n+1];
		memset(minn,0x3f,sizeof(minn));
		for(long long int i=1;i<=n;i++)cin>>a[i];
		for(long long int k=2;k<=n-1;k++){
			for(long long int i=k-1;i>=1;i--){
				for(long long int j=k+1;j<=n;j++){
					if(minn[i][j]>(a[k]-a[i])+(a[j]-a[k])){
						minn[i][j]=(a[k]-a[i])+(a[j]-a[k]);
						f[i][j]=1;
					}
					else if(minn[i][j]==(a[k]-a[i])+(a[j]-a[k])){
						f[i][j]++;
					}
				}
			}
		}
		for(long long int i=1;i<=n;i++){
			for(long long int j=1;j<=n;j++){
				if(f[i][j]==2)sum++;
			}
		}
		cout<<sum<<endl;
		t--;
	}
	return 0;
}
