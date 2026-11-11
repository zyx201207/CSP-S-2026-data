#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,q,n,d,x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>d;
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int l=1;l<=n;l++){ 
			for(int r=l+1;r<=n;r++){
				if((x[r]-x[l])%d!=0&&x[r]-x[l]<=(r-l)*d&&r-l>2){
					int temp=0;
					for(int i=l;i<=r;i++){
						if(x[i]-x[l]<=d&&x[r]-x[i]<=d) temp++;
					}
					if(temp==2) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
