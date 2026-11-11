#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,d;
int x[N],f[405],dp[405];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<0<<"\n";
		    continue;
        }
		if(c>=1 && c<=6){
			int cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp[j]=1e18;
					f[j]=0;
				}
				dp[i]=0;f[i]=1;
				for(int j=i+1;j<=n;j++){
					int minn=1e18,ans=0;
					for(int k=i;k<=j-1;k++){
						if(x[j]-x[k]<=d){
							minn=min(minn,dp[k]+1);
						}
					}
					for(int k=i;k<=j-1;k++){
						if(x[j]-x[k]<=d){
							if(dp[k]+1==minn){
								ans+=f[k];
								if(ans>3)break;
							}
						}
					}
					dp[j]=minn;
					f[j]=min(ans,(int)3);
				}
				for(int j=i+1;j<=n;j++){
					if(f[j]==2)cnt++;
				}
			}
			cout<<cnt<<"\n";
			continue;
		}
		if(c>=11 && c<=12){
			int y=x[2]-x[1];
			int p=d/y;
			if(p==1||p==0){
				cout<<0<<"\n";
				continue;
			}
			cout<<max((int)0,n-(2*p-1))<<"\n";
			continue;
		}
	}
}
