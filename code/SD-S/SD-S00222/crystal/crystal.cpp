#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],pre[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int res=0,l=1;
	for(int i=1;i<=n;i++){
		int cost=a[i]*(i-l)-(pre[i-1]-pre[l-1]);
		while(cost>m) l++,cost=a[i]*(i-l)-(pre[i-1]-pre[l-1]);
		res=max(res,i-l+1);
	}
	cout<<res;
	return 0;
}
