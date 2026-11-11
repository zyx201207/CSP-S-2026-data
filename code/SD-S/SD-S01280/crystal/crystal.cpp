#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int m,b[N][N],a[N],n,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n>1e4+10){
		int pp=0;
		int gg=1;
		while(1){
			pp+=gg;
			if(pp>m){
				cout<<gg;
				return 0;
			}
			gg++;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){
				b[i][j]=b[i][j]+a[j]-a[k];
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(b[i][j]<=m)
				ans=max(ans,j-i+1);
		}
	printf("%lld",ans);
	return 0;
} 
