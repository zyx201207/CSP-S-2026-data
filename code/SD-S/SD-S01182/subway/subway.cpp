#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],t[510][50010],a[510][50010],k[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int l=1;l<=n;l++){
		cin>>k[l];
		for(int i=1;i<=k[l];i++){
			cin>>a[i][k[l]]>>t[i][k[l]];
		}
	}for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=0;
		for(int l=x;l<=y;l++)ans+=w[l];
		cout<<ans<<endl;
	}
	return 0;
}
