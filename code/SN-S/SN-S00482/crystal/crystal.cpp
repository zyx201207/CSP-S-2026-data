//SN-S00482 谢俊哲 西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0;
vector<ll> a,d;
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	a.resize(n);//a 0-base
	d.resize(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end(),cmp);
	ll sum=0,len=0;
	for(ll i=1;i<n;i++){
		++len;
		sum=sum+len*(a[i]-a[i-1]);
		while(sum>m){
			sum=sum-(a[i]-a[i-len]);
			len--;
		}
		ans=max(ans,len);
	}//orz rp++
	printf("%lld\n",ans+1);
	return 0;
}
