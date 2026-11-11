#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
using namespace std;
int n,m,a[500010],pre[500010];
inline bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		int cnt=a[i+x-1]*x-pre[i+x-1]+pre[i-1];
		if(cnt<=m) return 1;
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<l-1;
	return 0;
}//Accepted
