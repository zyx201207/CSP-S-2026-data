#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e6;
int n,m;
int q[MAXN];
int d[MAXN];
int cost[MAXN];
signed main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+n+1);
	for(int i=2;i<=n;i++){
		d[i]=q[i]-q[i-1];
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		cost[i]=cost[i-1]+d[i]*(i-1);
		if(cost[i]>m){
			ans=i-1;
			break;
		}
	}
	if(ans==0&&cost[2]<=m) ans=n;
	cout<<ans<<endl;
	return 0;
}
