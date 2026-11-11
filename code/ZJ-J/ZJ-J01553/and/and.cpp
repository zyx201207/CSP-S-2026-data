#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],b[200010][32],f[32],v[1000010],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			int x=(1LL<<j);
			if(a[i]&x)b[i][j]=1;
			f[j]+=b[i][j];
		}
	}
	for(int i=30;i>=0;i--){
		if(f[i]>=m){
			ans+=(1LL<<i);
			for(int j=1;j<=n;j++){
				if(v[j]==0&&b[j][i]!=1){
					v[j]=1;
					for(int k=0;k<=30;k++){
						f[k]-=b[j][k];
					}
				}
			}
		}
	}cout<<ans;
	return 0;
}

/*
4 2
3 15 12 12


5 3
31 3 1 15 7

*/
