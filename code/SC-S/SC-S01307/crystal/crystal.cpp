#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],p[N],ans;
bool check(int l,int r){
	int sum=(r-l+1)*a[r]-(p[r]-p[l-1]);
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(int l=1,r=1;r<=n;r++){
		while(!check(l,r))l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 