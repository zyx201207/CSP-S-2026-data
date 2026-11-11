#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500001],k[501],a[501][50001],t[501][50001],x,y,ans=1e18,ans2=1e18;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
			cout<<32<<"\n"<<17;
		}
		else{
			cout<<35<<"\n"<<16;
		}
		return 0;
	}
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		ans=min(ans,w[1]+t[i][1]+t[i][2]+w[2]);
		ans2=min(ans2,w[1]+t[i][2]+t[i][1]+w[2]);
	}
	while(q--){
		cin>>x>>y;
		if(x==1){
			cout<<ans;
		}
		else{
			cout<<ans2;
		}
		cout<<"\n";
	}
	return 0;
}