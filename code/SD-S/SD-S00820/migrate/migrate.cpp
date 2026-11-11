#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,d,x[N],f[N][N],cnt[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=0x7fffffff;
		for(int i=1;i<=n;i++) f[i][i]=0,cnt[i][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<j;k++){
					if(x[j]-x[k]>d) continue;
					//f[i][j]=min(f[i][k]+1);
					if(f[i][k]+1==f[i][j]) cnt[i][j]++;
					else if(f[i][k]+1<f[i][j]){
						f[i][j]=f[i][k]+1;
						cnt[i][j]=cnt[i][k];
					}
				}
			}
		}
//		for(int i=1;i<=n;i++)
//			for(int j=i+1;j<=n;j++)
//				cout<<i<<' '<<j<<':'<<f[i][j]<<' '<<cnt[i][j]<<'\n';
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(cnt[i][j]==2) ans++;
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cnt[i][j]=0;
	}
	return 0;
} 
