#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e3+7;
int n,d;
int x[N];
int f[N][N];//the length of the best(shortest) path from u to v
int cnt[N][N];//the cnt of the best(shortest) path from u to v

void solve(){
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt[i][j]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])>d)	break;
				if(f[k][j]==f[k][i]+1){
					cnt[k][j]+=cnt[k][i];
				}
				else if(f[k][j]>f[k][i]+1){
//					printf("(%d,%d)->(%d,%d)",k,i,k,j);
//					printf("%d+=%d",cnt[k][j],cnt[k][i]);
					f[k][j]=f[k][i]+1;
					cnt[k][j]=cnt[k][i];
				}
			}
		}
	}
	int ans=0;
	for(int k=1;k<=n;k++){
		for(int i=k+1;i<=n;i++){
			
//			cout << k << ',' << i << ":\n    " << f[k][i];
//			cout <<"\n    " << cnt[k][i] << '\n';
			
			if(cnt[k][i]==2){
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		solve();
	}
}
