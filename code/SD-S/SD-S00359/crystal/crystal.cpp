#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll INF=1e18;
int n,l,r;
ll m,a[N],sum[N];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
ll readl(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=(ll)-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool check(int mid){
	ll minn=INF;
	for(int i=mid;i<=n;++i){
		minn=min(minn,a[i]*(mid-1)-sum[i-1]+sum[i-mid]);
	}
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=readl();
	for(int i=1;i<=n;++i){
		a[i]=readl();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i]; 
	}
	l=1;
	r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d",l);
	return 0;
}
