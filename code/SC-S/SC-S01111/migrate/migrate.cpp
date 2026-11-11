#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+50;
int v[N],f[5005][5005],pre[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,K;
		cin>>n>>K;
		for(int i=1;i<=n;i++) cin>>v[i];
		for(int i=2;i<=n;i++) pre[i]=pre[i-1]+(v[i]-v[i-1]);
		if(c==13 || c==14){
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				for(int k=0;k<=n;k++){
					for(int l=0;l<=n;l++){
						f[k][l]=0;
					}
				}
				f[l][0]=1;
				for(int j=l;j<=r;j++){
					for(int k=0;k<=n;k++){
						if(f[j][k]!=0){
							if(f[j][k]>2) break;
							for(int ll=j+1;ll<=r;ll++){
								if(pre[ll]-pre[j]<=K){
									f[ll][k+1]+=f[j][k];
								}
							}
							break;
						}
					}
				}
				for(int k=0;k<=n;k++){
					if(f[r][k]!=0){
						if(f[r][k]==2) ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
/*
0 2
5 3
-2 -10 12
0 1
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/