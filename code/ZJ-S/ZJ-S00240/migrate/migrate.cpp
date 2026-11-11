#include <bits/stdc++.h>
using namespace std;
const int N = 500+10;
long long a[N];
int cnt[N][N];
int num[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n;
		long long d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		memset(cnt,0x3f,sizeof(cnt));
		memset(num,0,sizeof(num));
		for(int i = 1;i < n;i++){
			cnt[i][i+1]=(a[i+1]-a[i]<=d?1:-1);
			num[i][i+1]=(a[i+1]-a[i]<=d?1:0);
		}
		for(int len = 2;len <= n;len++){
			for(int i = 1;i+len <= n;i++){
				int j = i+len;
				if(a[j]-a[i]<=d) cnt[i][j]=1;num[i][j]=1;
				for(int k = i+1;k < j;k++){
					if(cnt[i][k]==-1||cnt[k][j]==-1){
						cnt[i][j]=-1;
						num[i][j]=0;
					}else{
						int p = cnt[i][k]+cnt[k][j];
						if(p<cnt[i][j]){
							cnt[i][j]=p;
							num[i][j]=num[i][k]*num[k][j];
						}else if(p==cnt[i][j]){
							num[i][j]+=num[i][k]*num[k][j];
						}
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(num[i][j]==2){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}