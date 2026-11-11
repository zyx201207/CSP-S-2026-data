#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define il inline

const int N=5e5+5,mod=1e9+7,INF=(1LL<<60);

int n,m,ans,sum;
int a[N],p[N];

bool check(int x){
	for(int i=x;i<=n;i++){
		if(x*a[i]-(p[i]-p[i-x])<=m) return 1;
	}
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1ll;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	//	cout<<mid<<' '<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}/*
4 3
1 8 9 10
*/
