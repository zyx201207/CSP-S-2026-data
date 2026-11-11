#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long int ans,n,m,a[N],s[N],f[N][N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long int i=1;i<=n-1;i++){
		s[i]=s[i-1]+a[i+1]-a[i];
	}
	f[1][1]=0;
	for(long long int i=2;i<=n;i++){
		for(long long int j=i-1;j>=1;j--){
			f[i][j]=f[i][j+1]+s[i-1]-s[j-1];//cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
			if(f[i][j]<=m){
				ans=max(ans,i-j+1);
				
			}
		}
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9
  1 2 4 1
f[1][1]=0;
f[2][1]=f[2][2]+s[1]-s[0]=2
f[3][2]=f[3][3]+s[3]-s[2]=2
f[3][1]=f[3][2]+s[3]-s[1]=2+3=5;
f[4][3]=f[4][4]+s[3]=4
f[4][2]=f[4][3]+s[3]+s[2]=4+4+2=10

*/
