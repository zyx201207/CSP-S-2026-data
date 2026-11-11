#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,ans;
int w[500005],k[505],a[505][505],t[505][505],x[100005],y[100005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=i;j<=k[i]+i-1;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		ans+=w[x[i]]+w[y[i]];
		int k=x[i];
		for(int j=x[i];j<=y[i];j++){
			if(k==y[i]){
				break;
			}
			ans+=t[j][k];
			k++;
			ans+=t[j][k];
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
