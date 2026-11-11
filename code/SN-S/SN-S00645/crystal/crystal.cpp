#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m;
ll a[N];//记录原来的初始水晶能量值
ll b[N];//差分数组
ll c[N];//差分的前缀和
ll ans_c=0;//被改动的数字的数量，找到的最优选项 
/*
6 50
-30 -15 -7 25 31 100
   15  8  32  6  69 --差分 
   15  23 55 61 130 --前缀和 
*/ 
ll check(ll pos){//至少有一个可以被堆成a[pos] 
	ll x=m,sum=0,yuan=a[pos];
	if(x<b[pos-1]){//不可能的情况 
		return 1;
	} 
	for(ll i=pos;i>=1;i--){//有答案的话看一下到底有几种情况 
	    ll cha=c[pos-1]-c[i-1];
	    if(x>=cha){
	    	x-=cha;
	    	sum++;
		}
	}
	for(int i=pos+1;i<=n;i++){
		if(a[i]==yuan){
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n-1;i++){//差分应该比前缀和少一个数，因为是他的下一个减掉他 
		b[i]=a[i]-a[i-1];
	}
	for(ll i=1;i<=n-1;i++){
		c[i]=c[i-1]+b[i];
	}
	ll l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		ll f=check(mid);
		if(f==1){
			r=mid-1;
		}else{
			l=mid+1;
		}
		ans_c=max(ans_c,f);
	}
	/*
	for(int i=n;i>=1;i--){
		if(a[i]==a[i+1]){
			continue;
		}
		ll f=check(f);
		ans_c=max(ans_c,f);
		if(ans_c==n){
			break;
		}
	}
	*/
	cout<<ans_c;//ans_c要把自己也加上 
	return 0;
} 
