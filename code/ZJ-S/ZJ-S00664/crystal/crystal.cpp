#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N],ans[N],s[N],res=-1e18;
ll d;//公差，用于B特殊点 
bool f_1=1,f_2=1;
//贪心！贪心！贪心！
void solve_15pts_1(){
	ll r=1;
	while(r<=n){
		for(ll l=r-1;l>=1;--l){
		if(r*(r-l)-(l+r-1)*(r-l)/2<=m){
				ans[r]=r-l+1;
				res=max(ans[r],res);
			}
			if(r*(r-l)-(l+r-1)*(r-l)/2>m) break;
		}
		++r;
	}
	cout<<res;
} 
void solve_15pts_2(){
	ll r=1;
	while(r<=n){
		for(ll l=r-1;l>=1;--l){
			if(a[r]*(r-l)-(a[l]+a[r-1])*(((a[r-1]-a[l])/d)+1)/2<=m){
				ans[r]=r-l+1;
				res=max(res,ans[r]);
			}
			if(a[r]*(r-l)-(a[l]+a[r-1])*(((a[r-1]-a[l])/d)+1)/2>m) break;
		}
		++r;
	}
	cout<<res;
}
void solve_45pts(){
	s[0]=0;
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	} 
	for(ll i=1;i<=n;++i){
		ll goal=a[i];//以a[i]为目标
		ll sum=0;
		sum+=a[i]*(i-1)-s[i-1];//需要的操作价值 
		if(sum<=m){
			ans[i]=i;
		}
		else{
			ll p=m;
			ll pos=i;
			while(pos>=1){
				p-=(a[i]-a[pos]);
				if(p<0) break;
				pos--;
			}
			ans[i]=i-pos;
		}
	}
	for(ll i=1;i<=n;++i){
		res=max(res,ans[i]);
//		cout<<ans[i]<<' ';
	}
	cout<<res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	d=a[2]-a[1];
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=i) f_1=0;
	}
	for(int i=3;i<=n;++i){
		if(a[i]-a[i-1]!=d) f_2=0;
	}
	if(n<=5000){
		solve_45pts();
	}
	else if(n<=5e5){
		if(f_1){
			solve_15pts_1();//特殊性质A 
		}
		else if(f_2){
			solve_15pts_2();//特殊性质B 
		}
	}
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
4 4
1 2 3 4
4 7
1 3 5 7 9
*/

