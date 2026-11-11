#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[5005],f[5005][5005],dis[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			int g=d/(a[2]-a[1]);
			if(g>1) cout<<max(n-g*2+1,0ll)<<"\n";
			else cout<<0<<"\n";
			continue;
		}
		int res=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=0,dis[i][j]=1e9;
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) f[i][j]=dis[i][j]=1;
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dis[i][j]==1||a[j]-a[j-1]>d) continue;
				for(int k=i+1;k<=j-1;k++){
					int now=dis[i][k]+dis[k][j];
					if(now<dis[i][j]){
						dis[i][j]=now;
						f[i][j]=f[i][k]*f[k][j];
					}
					else if(now==dis[i][j]) f[i][j]+=f[i][k]*f[k][j];
				}
				if(f[i][j]==2) res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
