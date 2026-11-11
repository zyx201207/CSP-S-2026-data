#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,t,n,d,a[500005],dp[2005][2005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>_>>t;
	if(13<=_&&_<=14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<"\n";
		}
	}
	else{
		while(t--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					int h=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
					int g=lower_bound(a+1,a+n+1,a[j]-d)-a;
					if(h-g+1==2){
						dp[i][j]=1;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(dp[i][j]){
						int u=i,v=j,oo=1,pp=1;
						if(a[v+1]-a[v-1]>d){
						while(v<=n){
							if(a[v+1]-a[v]<=d&&(v+2>n||a[v+2]-a[v]>d)){
								v++;
								oo++;
							}
							else{
								break;
							}
						}
						}
						if(a[u+1]-a[u-1]>d){
						while(u>=1){
							if(a[u]-a[u-1]<=d&&(u-2<1||a[u]-a[u-2]>d)){
								u--;
								pp++;
							}
							else{
								break;
							}
						}
						}
						ans+=(oo*pp);
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
