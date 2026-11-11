#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[505];
int w[500005];
int t[505][500005];
int e[505][50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>e[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		int ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(e[i][j]==x){
					ans=ans+t[i][j]+k[x];
				}
				if(e[i][j]==y){
					ans=ans+t[i][j]+k[x];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
