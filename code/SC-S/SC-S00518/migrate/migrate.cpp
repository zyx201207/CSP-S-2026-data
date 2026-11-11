#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
signed main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int l=1,r=0;l<=n;l++){
			while(r+1<=n){
				r++;
				if(r-l+1==4){
					if(x[l]+d<x[r] && x[l+1]-x[l]<=d && x[l+2]-l[x]<=d && x[r]-x[l+1]<=d && x[r]-x[l+2]<=d){
						ans++;
					//	cout<<l<<","<<r<<'\n';
					}
				}
			}
			r=l+1;
		}
		cout<<ans<<'\n';
		ans=0;
		memset(x,0,sizeof(x));
	}
	return 0;
}