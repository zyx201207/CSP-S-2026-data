#include<bits/stdc++.h>
using namespace std;
const int M=5e3;
long long c,t,n,x[M+5],ans[M+5][M+5],cnt[M+5][M+5],sum,INF=1e15;
unsigned long long f,d;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>x[i];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				ans[i][j]=INF;
				cnt[i][j]=0;
			}
		}
		for(int l=1; l<=n; l++) {
			for(int r=l+1; r<=n; r++) {
				f=x[r]-x[l];
				if(f<=d) {
					ans[l][r]=1;
					cnt[l][r]=1;
				} else break;
			}
		}
		for(int len=3; len<=n; len++) {
			int maxl=n-len+1;
			for(int l=1; l<=maxl; l++) {
				int r=l+len-1;
				for(int k=l+1; k<r; k++) {
					f=x[k]-x[l];
					if(f<=d&&cnt[l][k]!=0&&cnt[k][r]!=0&&(ans[l][r]>ans[l][k]+ans[k][r])) {
						ans[l][r]=ans[l][k]+ans[k][r];
						cnt[l][r]=cnt[l][k]*cnt[k][r];
					} else if(f<=d&&cnt[l][k]!=0&&cnt[k][r]!=0&&(ans[l][r]==ans[l][k]+ans[k][r])) {
						cnt[l][r]+=cnt[l][k]*cnt[k][r];
					} else if(f>d)break;
				}
			}
		}
		sum=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(cnt[i][j]==2)sum++;
			}
		}
		cout<<sum<<endl;
		for(int i=1; i<=n; i++) {
			x[i]=0;
//			for(int j=1; j<=n; j++)cout<<cnt[i][j]<<" ";
//			cout<<endl;
//			for(int j=1; j<=n; j++)cout<<ans[i][j]<<" ";
//			cout<<endl;
			for(int j=1; j<=n; j++) {
				ans[i][j]=INF;
				cnt[i][j]=0;
			}
//			cout<<endl;
		}
	}
	return 0;
}

