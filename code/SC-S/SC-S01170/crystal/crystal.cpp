#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N],pre[N];
bool check(int l,int r){
	if((r-l)*a[r]-(pre[r]-pre[l-1])>m){
		return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	ll ans=0;
	for(int i=2;i<=n;i++){
		ll l=1,r=i,mid=(l+r)/2;
		while(true){
			if(l==r){
				break;
			}
			mid=(l+r)/2;
			if(check(mid,i)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		int flag=0;
		if(check(l-1,i))flag=1;
		ans=max(ans,i-l+flag);
	}
	cout<<ans;
	return 0;
}