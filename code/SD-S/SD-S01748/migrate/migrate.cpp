#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int c,t,n,a[N],f[N][N],cnt[N][N],ans,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(f,0x3f,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d)break;
				f[i][j]=1;
				cnt[i][j]=1;
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>0;j--){
				if(a[i]-a[j]>d)break;
				for(int k=1;k<j;k++){
					if(f[k][j]+1<f[k][i]){
						f[k][i]=f[k][j]+1;
						cnt[k][i]=cnt[k][j];
					}else if(f[k][j]+1==f[k][i])cnt[k][i]+=cnt[k][j];
				}
			}
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}cout<<ans<<"\n";
	}
	return 0;
}

