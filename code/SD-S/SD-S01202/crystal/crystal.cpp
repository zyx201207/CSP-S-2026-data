#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+10;
ll INF=1e12;
ll n,m,a[N],d,base,maxx=-INF,minn=INF,ans;
bool flag=true;
ll check(ll mid){
	ll pos=upper_bound(a+1,a+1+n,mid)-a-1,cnt=0;
	for(int i=pos;i>=1;i--){
		cnt+=mid-a[i];
		if(cnt>m){
			return pos-i;
		}
	}
	return pos;
}
void dfs(ll L,ll R){
	if(L==R||L==R-1){
		cout<<max(max(check(L),check(R)),ans);
		return ;
	}
	if(L==minn&&R==maxx){
		ans=check((L+R+1)>>1);
	}
	ll mid=(L+R+1)>>1;
	if(check((mid+R+1)>>1)<ans){
		dfs(L,mid);
	}else{
		dfs(mid,R);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cout<<i<<" ";
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i!=1&&a[i]-a[i-1]!=d){
			flag=false;
		}else{
			d=a[i]-a[i-1];
		}
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	if(flag){//a[i]==i||a[i]为等差数列 
		base=a[1]-d;
		ll i,cnt=0;
		for(i=1;i*d+base<=a[n];i++){
			cnt+=i*d;
			if(cnt>m){
				cout<<i;
				return 0;
			}
		} 
		cout<<i+1;
		return 0;
	}
	dfs(minn,maxx);
	return 0;
}
