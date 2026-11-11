#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,q;
map<pair<int,int>,int> e;
int vis[500005],dis[500005];
int w[500005],a[500005],t[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=2;j<=k;j++){
			e[{a[j-1],a[j]}]=t[j-1]+t[j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x>y){
			int p=0;
			p=x;
			x=y;
			y=p;
		}
		int ans=w[x]+w[y];
		for(int i=x;i<y;i++){
			ans+=e[{i,i+1}];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//我该在哪里停留
//A=line 

