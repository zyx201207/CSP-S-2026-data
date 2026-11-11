#include<bits/stdc++.h>
using namespace std;
long long c,n,ans,m,d,q,w[500010],k[510],a[510][50010],t[510][50010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
		ans+=t[i][1]+t[i][2];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<ans+w[x]+w[y];
	}
	//不可以骗分总司令
	return 0;
}