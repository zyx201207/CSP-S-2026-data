#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N=5e5+5;
ll n,m,a[N],_Furina_,_kkksc03_,nw[N],tail,pos=1,ans=1;

bool cmp(ll x,ll y){
	return x>y;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2==0)_Furina_=(a[n/2]+a[n/2+1])/2,_kkksc03_=n/2;
	else if(n%2!=0)_Furina_=a[(n+1)/2],_kkksc03_=(n+1)/2;
	for(ll i=1;i<_kkksc03_;i++)nw[++tail]=a[i];
	sort(nw+1,nw+tail+1,cmp);
	while(m--){
		nw[pos]++;
		if(nw[pos]==_Furina_)pos++;
	}
	for(ll i=_kkksc03_+1;i<=n;i++)if(a[i]==_Furina_)ans++;
	for(ll i=1;i<=tail;i++)if(nw[i]==_Furina_)ans++;
	cout<<ans;
	return 0;
}

//I don't know how to solve this problem, as you see I could only go through the examples. 
