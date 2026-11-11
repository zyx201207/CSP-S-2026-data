#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+5;
int a[N],pre[N],nxt[N],n,d;
namespace S3{
	int f[N],g[N];
	void sol(){
		int ans=0;
		int fl=0;
		for(int i=1;i<=n;i++){
			f[i]=0;
			g[i]=1;
			fl=0;
			int xb=i;
			for(int j=i+1;j<=n;j++){
				while(a[j]-a[xb]>d){
					xb++;
				}
				if(xb==j){
					break;
				}
				f[j]=f[xb]+1;
				g[j]=g[xb];
				for(int k=xb+1;k<=j-1;k++){
//					cout<<j<<" "<<k<<"##\n";
					if(f[k]+1==f[j]){
						g[j]+=g[k];
					}
					else{
						break;
					}
					if(g[j]>=3){
						break;
					}
				}
				if(g[j]==2){
					ans++;
				}
//				cout<<j<<" "<<f[j]<<" "<<g[j]<<"++\n";
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T,cas=0;
	cin>>C>>T;
	while(T--){
		cas++;
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
//		if(C<=10){
			S3::sol();
//		}
	}
	return 0;
}