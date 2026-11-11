#include<bits/stdc++.h>
using namespace std;
long long i,j,n,m,x,g,ans,a[35],e[200010],f[200010][35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>x;
		for(j=30;j>=0;j--){
			if(x>=(1<<j)){
				x-=(1<<j);
				f[i][j]=1;
			}else{
				f[i][j]=0;
			}
		}
	}
	for(i=1;i<=n;i++) e[i]=1;
	for(i=30;i>=0;i--){
		g=0;
		for(j=1;j<=n;j++){
			if(e[j]){
				g+=f[j][i];
			}
		}
		if(g>=m){
			a[i]=1;
			for(j=1;j<=n;j++)
				if(f[j][i]==0) e[j]=0;
		}else{
			a[i]=0;
		}
	}
	for(i=30;i>=0;i--) ans=ans*2+a[i];
	cout<<ans;
	return 0;
}

