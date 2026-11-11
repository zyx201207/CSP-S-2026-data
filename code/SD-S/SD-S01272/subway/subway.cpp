#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#define debug(x) cerr<<"debug:"<<__LINE__<<#x<<" "<<x
using namespace std;
const int N=5e5+10,INF=3e18+10;
int n,m,w,v,a[N],mn,mx=-INF,ans,sum,x;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>mn>>n>>m>>w>>v;
	for(int i=1;i<=m;i++){
		cin>>x;
		ans+=x;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>sum;
			ans+=sum;
		}
	}
	for(int i=1;i<=v;i++){
		cin>>x>>sum;
	}
	cout<<ans;
	return 0;
}


















































