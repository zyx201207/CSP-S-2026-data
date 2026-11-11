#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],a[N][M],t[N][M],k[N],ans;
bool f[N][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			f[i][a[i][j]]=1;
		}
	}
	cin>>q;
	while(q--){
		int st,ed;
		bool ok=0;
		cin>>st>>ed;
		ans+=w[st]+w[ed];
		int tmp=1e18;
		for(int i=1;i<=n;i++){
			if(f[i][st]==1&&f[i][ed]==1){
				ok=1;
				tmp=min(tmp,t[i][st]+t[i][ed]);
			}
		}
		if(ok==1){
			cout<<ans+tmp<<endl;
			continue;
		}
	}
	return 0;
}