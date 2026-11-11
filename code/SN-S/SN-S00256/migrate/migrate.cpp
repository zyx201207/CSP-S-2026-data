#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,x[N],q[N],f[5005][5005],cnt[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T){
		T--;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<=500){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					f[i][j]=n+1;
					cnt[i][j]=0;
				}
				f[i][i]=0;
				cnt[i][i]=1;
			}
			for(int i=1;i<=n;i++){
				for(int j=i-1;j>0;j--){
					if(x[i]-x[j]>d) break;
					for(int k=1;k<=j;k++){
						if(f[k][i]>f[k][j]+1){
							f[k][i]=f[k][j]+1;
							cnt[k][i]=cnt[k][j];
						}
						else if(f[k][j]+1==f[k][i]){
							cnt[k][i]+=cnt[k][j];
						}
//						cout<<"i="<<i<<" j="<<j<<" k="<<k<<" f_k_j="<<f[k][j]<<" cnt_k_j="<<cnt[k][j]<<" f_k_i="<<f[k][i]<<" cnt_k_i="<<cnt[k][i]<<"\n";
					}
				}
//				cout<<"\n";
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
//					cout<<"i="<<i<<" j="<<j<<" cnt="<<cnt[i][j]<<"\n";
					if(cnt[i][j]==2){
						ans++;
//						cout<<"i="<<i<<" j="<<j<<"\n";
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
