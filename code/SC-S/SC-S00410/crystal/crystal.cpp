#include<bits/stdc++.h>
#define ll long long
const int N=5e5+10;
using namespace std;
ll a[N];
ll pre[N];
ll n,m;
bool ck(int x,int i){
	ll res;
	res=x*a[i]-(pre[i+x-1]-pre[i-1]);
	return res<=m;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	ll ans=1;
	ll cnt=1;
	for(int i=1;i<=n;i++){
		cnt=1;
		int l=1,r=n-i+1;
		ll mid;
		while(l<=r){
			mid=(l+r)/2;
			if(ck(mid,i)){
				l=mid+1;
				cnt=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}