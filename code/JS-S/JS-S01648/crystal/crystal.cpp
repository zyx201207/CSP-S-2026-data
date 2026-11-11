#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,minn=1e13,maxx=-1e13;
int n,ans,f;
ll a[500010];
ll b[500010];
int solve(int x){
	for(int i=1;i<=n;i++) b[i]=abs(a[i]-x);
	sort(b+1,b+n+1);
	ll m2=m;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(m2<b[i]) break;
		m2-=b[i];
		ans++;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	cin>>n>>m;
	ll last;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2) last=a[i]-a[i-1];
		else if(a[i]-a[i-1]!=last) f=1;
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	if(!f){
		if(last>m){
			cout<<1;
			return 0;
		}
		for(ll i=1;i<=n;i++){
			double x=1;
			x+=1.0*last*i;
			x-=last;
			x=x*i/2;
			if(x>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	for(ll x=minn;x<=maxx;x++) ans=max(ans,solve(x));
	cout<<ans;
	return 0;
}
