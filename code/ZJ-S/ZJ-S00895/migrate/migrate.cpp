#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T;
int n,d;
int a[100001];
int f[1001][1001];
int cnt[1001][1001];
int ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	memset(f,0x3f,sizeof(f));
	memset(cnt,0x3f,sizeof(cnt));
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(C==11||C==12){
			int dif=a[2]-a[1];
			d/=dif;
			int len=(d/dif)*2-1;
			if(d==1) cout<<0<<endl;
			else cout<<max(n-len,1ll*0)<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			f[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int dis=abs(a[i]-a[j]);
				if(dis<=d) f[i][j]=f[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=k;i++){
				for(int j=k;j<=n;j++){
					if(f[i][j]==1) continue;
					if(f[i][j]==f[i][k]+f[k][j]){
						cnt[i][j]++,cnt[j][i]++;
						f[i][j]=f[j][i]=-1;
					}
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[j][i]=f[i][k]+f[k][j];
						cnt[i][j]=cnt[j][i]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}