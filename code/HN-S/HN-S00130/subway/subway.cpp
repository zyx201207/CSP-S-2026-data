#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[1005],a[1005],t[1005],dis[1005][1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i],dis[i][i]=0;
	while(n--){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++) cin>>a[i]>>t[i];
		for(int i=1;i<=k;i++) for(int j=1;j<i;j++) dis[a[j]][a[i]]=dis[a[i]][a[j]]=min(min(dis[a[j]][a[i]],dis[a[i]][a[j]]),t[i]+t[j]);
	}
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<w[s]+w[t]+dis[s][t]<<"\n";
	}
	return 0;
}
