#include<bits/stdc++.h>
using namespace std;
int c,T;
int a[5005],f[5005][5005],cnt[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		int n,d,ans = 0;
		scanf("%d %d",&n,&d);
		for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
		for(int i = 1;i<=n;i++)
			for(int j = i+1;i<=n;i++){
				if(a[j] - a[i] <= d)f[i][j] = 1;
				else f[i][j] = 1E9;
			}
		for(int len = 1;len<=n;len++){
			for(int i = 1;i+len-1<=n;i++){
				int j = i+len-1;
				for(int k = i+1;k<j;k++){
					if(f[i][k] == 1E9 || f[k][j] == 1E9)continue;
					if(f[i][j] > f[i][k]+f[k][j])f[i][j] = f[i][k]+f[k][j],cnt[i][j]=1;
					if(f[i][j] == f[i][k]+f[k][j])cnt[i][j]++;
				}
			}
		}
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++){
				if(cnt[i][j] == 2)ans++;
			}
		cout << ans << endl;
	}
}