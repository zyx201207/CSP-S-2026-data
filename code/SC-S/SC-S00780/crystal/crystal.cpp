#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=5e5+10,M=1e12+1;
int n,m,a[N],sum[N],ans;
int check(int x){
	int s=x*a[x];
	int t=s-m-sum[x];
	int res=0;
	int l=1,r=x;
	while(l<r){
		int mid=l+r>>1;
		if((x-mid+1)*a[x]-(sum[x]-sum[mid-1])<=m) r=mid;
		else l=mid+1;
	}return x-l+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,1,n){
    	cin>>a[i];a[i]=a[i];
	}sort(a+1,a+n+1);
	rep(i,1,n){
		sum[i]=a[i]+sum[i-1];
	}int x;
	rep(i,1,n){
		ans=max(ans,check(i));
	}
	cout<<ans;
	return 0;
}
/*
luogu:needma

高三了 一年没碰确实比较生了

:( 

感觉不能上200 t1依旧简单 

欢迎报考sszx谢谢喵 
*/

