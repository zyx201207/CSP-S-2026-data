#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N],pre[N];
ll sum(ll i,ll j){
	return pre[j]-pre[i-1];
}
ll ans[N];
bool check(ll k,ll idx){
	ll use=1ll*(idx-k)*a[idx]-sum(k,idx-1);
	//if(3843<=idx&&idx<=3853)printf("k=%d,idx=%d:use=%d(%d-%d)\n",k,idx,use,1ll*(idx-k)*a[idx],sum(k,idx-1));
	if(use>m)return true;
	else return false;
}
ll find_k(ll idx){
	ll l=1,r=idx;
	ll mid=0,ans=idx;
	while(l<=r){
		mid=(l+r)>>1;
		//if(3843<=idx&&idx<=3853)printf("l=%d,r=%d,mid=%d,check=%d\n",l,r,mid,check(mid,idx));
		if(check(mid,idx)){
			ans=mid;
			l=mid+1;
		}
		else {
			ans=mid;
			r=mid-1;
		}
	}
	//printf("finally k=%d\n",ans);
	for(int i=max(1ll,ans-2);i<=min(ans+2,1ll*idx);i++){
		if(!check(i,idx)){
			return i;
		}
	}
	return ans;
}
ll maxn=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	//for(int i=1;i<=n;i++)if(3843<=i&&i<=3853)printf("%d ",a[i]);
	for(int i=2;i<=n;i++){
		//if(3843<=i&&i<=3853)printf("----------------\nnow calc(%d)\n-------------------------\n\n",i);
		ll k=find_k(i);
		ans[i]=ans[i]+i-k;
		maxn=max(maxn,ans[i]);
		//if(3843<=i&&i<=3853)printf("ans[%d]=%d\n",i,ans[i]);
	}
	//cerr<<a[4235]<<" "<<1ll*(4235-1)*a[4235]-sum(1,4234)<<'\n';
	cout<<maxn<<'\n';
	return 0;
}
/*

20 89665
53 6 345  6  34 6 7 65 7 687 54 76  65643565 5423 3356 5 63 462333 5 345
*/

