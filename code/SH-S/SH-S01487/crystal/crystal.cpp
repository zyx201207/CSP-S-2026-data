#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define ll long long
ll n,m;
ll a[MAXN];

//前面所有元素想要加到i需要的操作次数 
ll need[MAXN];

bool check(ll len){
	len-=1;
	for(int i=len;i<n;i++){//从第i-len到i的 
		ll needt=(need[i]-need[i-len]-(a[i]-a[i-len])*(i-len));
//		cout<<i-len<<" "<<i<<" : "<<needt<<"\n"; 
		if(needt<=m){
			return true;
		}
	}
	return false;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	need[0]=0;
	for(ll i=1;i<n;i++){
		need[i]=need[i-1]+abs(a[i]-a[i-1])*(i);
	}
//	for(ll i=0;i<n;i++){
//		cout<<need[i]<<" ";
//	}
//	cout<<"\n";
	//挑选个数 
	ll l=0,r=n;
	ll ans=0;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
//		cout<<l<<" "<<r<<"\n";
	}
	cout<<ans;
	return 0;
} 
