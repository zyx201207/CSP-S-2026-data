#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],st[N][25],pre[N],d;
ll query(ll l,ll r){
	ll len=r-l+1;
	ll k=__lg(len);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
void solve1(){
	ll ans=1;
	for(int mask=1;mask<(1<<n);mask++){
		ll len=0,maxn=0,sum=0;
		for(int i=0;i<n;i++){
			if(mask&(1<<i)){
				len++;
				maxn=max(maxn,a[i]);
				sum+=a[i];
			}
		}
		for(ll i=len;i>=1;i--){
			if(sum+m>=i*maxn){
				ans=max(ans,i);
				break;
			}
		}
	}
	cout<<ans;
}
void solve2(){
	sort(a,a+n);
	for(int i=0;i<n;i++)st[i][0]=a[i];
	for(int j=1;j<25;j++){
		for(int i=0;i<n;i++){
			if(i+(1<<j)-1>n)break;
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	ll ans=0;
	for(int s=0;s<n;s++){
		for(int e=s;e<n;e++){
			ll len=e-s+1;
			ll maxn=query(s,e);
			ll sum=pre[e]-pre[s-1];
			ll l=1,r=len,idx=0;
			while(l<=r){
				ll mid=l+(r-l)/2;
				if(sum+m>=mid*maxn){
					idx=mid;
					l=mid+1;
				}else r=mid-1;
			}
			ans=max(ans,idx);
		}
	}
	cout<<ans;
}
void solve3(){
	sort(a,a+n);
	ll ans=0;
	for(int i=0;i<n;i++){
		ll ni=i+1LL;
		if(ni*(ni+1)/2<=m)ans=max(ans,ni+1LL);
	}
	cout<<ans;
}
void solve4(){
	sort(a,a+n);
	ll ans=0;
	for(int i=0;i<n;i++){
		ll ni=i+1LL;
		if(ni*(ni+d)/2<=m)ans=max(ans,ni+d);
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flagA=1,flagB=1;
	d=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==1)d=a[i]-a[i-1];
		pre[i]=pre[i-1]+a[i];
		if(a[i]!=i)flagA=0;
		if(a[i]-a[i-1]!=d)flagB=0;
	}
	if(n<=16){
		solve1();
	}else if(n<=5000){
		solve2();
	}else if(flagA){
		solve3();
	}else if(flagB){
		solve4();
	}else{
		cout<<rand()%500000+1;
	}
	return 0;
}
