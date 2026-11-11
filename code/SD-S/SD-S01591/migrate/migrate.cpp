#include<bits/stdc++.h>
using namespace std;
const long long maxn=6e5+7,inf=1e18+7;
long long c,t,f[310][310],cnt[310][310],n,d,x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				f[i][j]=inf;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			f[i][i]=0;
			cnt[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d&&i!=j){
					f[i][j]=1;
					cnt[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j||f[i][j]==1||i==k||j==k){
						continue;
					}
					if(f[i][j]>f[i][k]+f[k][j]&&f[i][k]!=f[0][0]&&f[k][j]!=f[0][0]){
						f[i][j]=f[i][k]+f[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(f[i][j]==f[i][k]+f[k][j]&&f[i][k]!=f[0][0]&&f[k][j]!=f[0][0]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
