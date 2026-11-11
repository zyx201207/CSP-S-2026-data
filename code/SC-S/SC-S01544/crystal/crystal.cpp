#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=5e6+5;
ll n,m,ans,used_,sum;
ll a[N];//,f[N];
ll cheak(ll);	//判断用 m最多可以弄几个 
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	//cin>>n>>m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;++i){
		//cin>>a[i];
		scanf("%lld",&a[i]);
		//f[i]=f[i-1]+(i-1)*abs(a[i]-a[i-1]);
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;++i)ans=max(ans,cheak(i));
	//cout<<ans;
	printf("%d",ans);
	return 0;
}
ll cheak(ll x){
	const ll o=x;
	sum=0;
	used_=0;
	while(x!=0){
		if(used_+(a[o]-a[x])>m)break;
		sum++;
		used_+=(a[o]-a[x]);
		x--;
	}
	return sum;
}