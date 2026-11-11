#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#define debug(x) cerr<<"debug:"<<__LINE__<<#x<<" "<<x
using namespace std;
const int N=2e6+100,INF=3e18+10;
int n,m=1,w,a[N],mn=INF,mx=-INF,ans,sum=1,x,y;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>x>>w;
	while(w--){
		cin>>n>>y;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==4&&a[3]-a[1]<=y)cout<<1<<endl;
		else cout<<0<<endl;
		//cout<<ans<<endl;
	}
	return 0;
}
