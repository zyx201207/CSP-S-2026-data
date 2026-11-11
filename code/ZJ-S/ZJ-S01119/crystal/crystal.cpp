#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500010;
ll n,m,i,a[N],s[N],t,w,mid,bao;
bool check(ll x){
	ll i,sum,ed;
	for(i=1;i<=n-x+1;i++){
		ed=i+x-1;
		sum=a[ed]*x-(s[ed]-s[i-1]);
		if(sum<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	t=1;w=n;
	while(t<=w){
		mid=(t+w)/2;
		if(check(mid))t=mid+1,bao=mid;
		else w=mid-1;
	}
	cout<<bao;
	return 0;
}

