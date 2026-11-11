#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
ll a[500005],s,ans[500005],cnt=1,sum,cute;
queue<ll> q;
ll tol,ert;
void init(){
	s-=q.front();
	q.pop();
	k--;
	sum++;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==a[i+1]&&i!=n)
			ert++;
	}
	if(ert==n-1){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		s+=a[i];
		k++;
		ll cute=s+m;
		if(cute/k>=a[i]){
			q.push(a[i]);
			ans[cnt]++;
		}
		else{
			if(cute/k<a[i]){
				init();
			}
			cnt+=1;
			ans[cnt]=ans[cnt-1]+1-sum;
		}
	}
	sort(ans+1,ans+cnt+1);
	cout<<ans[cnt];
	return 0;
}