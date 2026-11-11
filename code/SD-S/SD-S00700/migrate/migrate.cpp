#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int t,n,d,x[5100],f[5100][5100],cnt[5100][5100];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i],f[i][i]=cnt[i][i]=1;
		sort(x+1,x+1+n);
		int ans=0;
		for(int l=2;l<=n;l++){
			for(int i=1;i+l-1<=n;i++){
				int j=i+l-1;
				f[i][j]=1e18;
				cnt[i][j]=0;
				if(x[j]-x[i]<=d){
					cnt[i][j]=1;
					f[i][j]=2;
				}
				if(l==2)continue;
				for(int k=i+1;k<j;k++){
					if(x[j]-x[k]>d)continue;
					if(f[i][k]+1<f[i][j]){
						f[i][j]=f[i][k]+1;
						cnt[i][j]=cnt[i][k];
//						cout<<i<<" "<<k<<" "<<j<<" "<<f[i][k]<<" "<<f[k][j]<<endl;
					}
					else if(f[i][k]+1==f[i][j]){
						cnt[i][j]+=cnt[i][k];
					}
				}
//				cout<<t<<" "<<i<<" "<<j<<" "<<f[i][j]<<" "<<cnt[i][j]<<endl;
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
} 
