#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d,q,x,y,k,i,j,w[500010];
vector<int>a[500010],b[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.ans","w",stdout);
	cin>>n;cin>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++)cin>>x>>y,a[x].push_back(i),b[x].push_back(y);
	}
	while(q--){
		cin>>x>>y;
		cout<<abs(x*x-y*y)<<"\n";
	}
}
