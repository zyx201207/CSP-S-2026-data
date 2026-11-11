#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=5e5+7;
int n;
ll m,pfx[N],a[N];
ll sum(int l,int r){
	return pfx[r]-pfx[l-1];
}bool check(int len){
	for(int i=len;i<=n;i++){
		ll maxv=a[i],tot=sum(i-len+1,i);
		ll need=maxv*len-tot;
		if(need<=m) return 1;
	}return 0;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pfx[i]=pfx[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}cout<<l;
}