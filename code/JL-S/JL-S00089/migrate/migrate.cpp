#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5000050];
int n,d;
int floyd[305][305];
int c;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c<=6){
		memset(floyd,0x3,sizeof floyd);
		for(int i=1;i<=n;i++){
			floyd[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					floyd[i][j]=min(floyd[i][j],1LL);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					floyd[i][j]=floyd[j][i]=min(floyd[i][k]+floyd[k][j],min(floyd[i][j],floyd[j][i]));
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;i<=n;j++){
				int cnt=0;
				for(int k=1;k<=n;k++){
					if(floyd[i][j]==floyd[i][k]+floyd[k][j]){
						cnt++;
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}	
	if(c==11||c==12){
		int ans=0;
		int dl=a[2]-a[1];
		int ma1=d/dl;
		for(int i=1;i<=n;i++){
			if(n-i<2*ma1){
				ans+=2*ma1-ma1-1;
			}
			else if(n-i>ma1){
				ans+=n-ma1;
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}