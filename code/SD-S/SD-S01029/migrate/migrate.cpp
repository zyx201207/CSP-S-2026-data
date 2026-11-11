#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000007],ans,f[207][207];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		sort(x+1,x+n+1);
		x[0]=-0x3f3f3f3f3f3f3f3fll;
		for(int t=1;t<n;++t){
			memset(f,0,sizeof(f));
			f[t][0]=1;
			for(int i=t+1;i<=n;++i){
				for(int k=1;k<=n;++k){
					for(int j=i-1;j>=t&&x[i]-x[j]<=d;--j){
						f[i][k]+=f[j][k-1];
					}
				}
			}
			for(int i=t+1;i<=n;++i){
				for(int k=1;k<=n;++k){
					if(f[i][k]>0){
						ans+=(f[i][k]==2);
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;//ίχ 
}//
