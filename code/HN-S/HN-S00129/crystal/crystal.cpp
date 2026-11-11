#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],s[N]; 
bool check(ll x,ll sjz,ll sjs){
	ll yingde=sjz*(sjs-x+1);
	ll shiji=s[sjs]-s[x-1];
	ll yingjia=yingde-shiji;
//	cout<<x<<" "<<sjz<<" "<<sjs<<"\t";
//	cout<<yingde<<" "<<shiji<<" "<<yingjia<<"\n";
	if(yingjia>m)return 0;
	else return 1;
}
void solve1(){
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	ll  maxx=0;
	for(ll i=1;i<=n;i++){
		ll l=0,r=i+1;
		while(l+1!=r){
			ll  mid=(l+r)/2; 
			if(check(mid,a[i],i))r=mid;
			else l=mid;
		}
		maxx=max(maxx,(i-r+1));
	}
	cout<<maxx;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	solve1();
	return 0;
}

