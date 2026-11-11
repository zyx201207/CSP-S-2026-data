#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[100500];
int ans=0;
int a[100500];
int t[1050][1050];
int x,y;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=n;i++){
		int a1x,t1x,a2x,t2x;
		cin>>a1x>>t1x>>a2x>>t2x;
		a[a1x]=a2x;
		t[a1x][a2x]=t1x+t2x;
	}
	while(q--){
		cin>>x>>y;
		ans=0;
		ans+=w[x];
		ans+=w[y];
		while(x!=y){
			ans+=t[x][a[x]];
			x=a[x];
		}
		cout<<ans<<endl;
	}
	return 0;
}