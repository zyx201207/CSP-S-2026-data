#include<bits/stdc++.h>
#define ll long long
#define F(l,r,i) for(int i=l;i<=r;i++)
#define Fa(l,r,i) for(int i=r;i>=l;i--)
using namespace std;
ll n,m,maxn,minn=1e9,b[500010],a[500010],ans,p[500010];
bool flag=true;
bool cmp(ll x,ll y){
	return x>y;
}
void dfs(ll step,ll last){
	if(step==m){
		ll sum=p[1];
		F(2,m,i) sum=(sum&p[i]);
		if(sum>=ans){
			ans=sum;
		}
		return;
	}
	F(last+1,n,i){
		p[step+1]=a[i];
		dfs(step+1,i);
	}
	return;
}
bool check(ll num){
	ll l=(ll)(log(num)/log(2));
	if(pow(2,l)==num) return true;
	return false;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	F(1,n,i){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(!check(a[i])) flag=false;
		b[i]=(ll)(log(b[i])/log(2));
		minn=min(minn,a[i]);
	}
	if(flag){
		sort(b+1,b+n+1,cmp);
		cout<<b[m]<<endl;
	}
	else if(m==1) cout<<maxn<<endl;
	else if(m==2){
		F(1,n,i){
			F(i+1,n,j) ans=max(ans,(a[i]&a[j]));
		}
		cout<<ans<<endl;
	}
	else if(m==n){
		ll ans=a[1];
		F(2,n,i) ans=(ans&a[i]);
		cout<<ans<<endl;
	}
	else if(m==n-1){
		bool flaga=false;
		ll ans=pow(2,31)-1;
		F(1,n,i){
			if(a[i]!=minn||(a[i]==minn&&flaga)) ans=(ans&a[i]);
			else flaga=1;
		}
		cout<<ans<<endl;
	}
	else{
		dfs(n,0);
		cout<<ans<<endl;
	}
	return 0;
}
