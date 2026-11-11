#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][50005],t[505][50005],x,y,ans,wa[505],wy[505],f=1;
signed main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			wa[a[i][j]]=i;
			wy[a[i][j]]=j;
		}
	}
	while(q--){
		f=1;
		ans=0;
		cin>>x>>y;
		x--;y--;
		ans+=(w[x]+w[y]);
		for(int i=0;i<k[wa[x]];i++){
			if(a[wa[x]][i]==y+1){
				cout<<ans+t[wa[x]][wy[x]]+t[wa[x]][i]<<'\n';
				f=0;
				break;
			}
		}
		if(f==0){
			continue;
		}
		ans+=(t[wa[x]][wy[x]]+t[wa[y]][wy[y]]);
		for(int i=0;i<k[wa[x]];i++){
			f=1;
			for(int j=0;j<k[wa[y]];j++)
				if(a[wa[x]][i]==a[wa[y]][j]){
					cout<<ans+t[wa[x]][i]+t[wa[y]][i]<<'\n';
					f=0;break;
				}
			if(f==0)break;
		}
	}
	return 0;
}
