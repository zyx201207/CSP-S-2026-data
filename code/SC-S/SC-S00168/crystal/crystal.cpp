#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5; 
int n,m,a[N],f[N][101],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=a[n]+m;i++) f[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j+n-i<=ans) continue;
			int op=(1<<(j-1));
			if(j==1) op=2;
			for(int k=(a[i]+op-1)/op;k<=(a[i]+m)/op;k++){
				f[j][k]=f[j-1][k]+op*k-a[i];
				if(f[j][k]<=m){
					ans=max(ans,j);
				}
			}
		}
	}
	cout<<ans;
}
