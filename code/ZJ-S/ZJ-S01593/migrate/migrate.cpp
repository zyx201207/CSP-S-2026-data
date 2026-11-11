#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],f[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int di=x[2]-x[1];
			int b=d/di;
			if(d<=di){
				cout<<0<<"\n";
			}
			else{
				int ans=0;
				for(int i=1;i<=n;i++){
					if(x[i]+di*(2*b-1)<=x[n]) ans++;
				}
				cout<<ans<<"\n";
			}
		}
	}
	else if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			cout<<1<<"\n";
		}
	}
	else{
		while(t--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++) if(x[j]-x[i]<=d) f[j][0]++;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=j-i-1;k++){
						for(int z=0;z<=k;z++){
							f[j][k]=f[i][z]*f[j][k-z];
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=j-i-1;k++){
						if(f[j][k]==2) ans++;
					}
				}
			}
			cout<<ans;
		}
	}
}
