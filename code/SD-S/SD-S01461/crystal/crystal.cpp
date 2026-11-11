#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
ll read(){
	ll f=1,sum=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=(c-'0');
		c=getchar();
	}
	return sum*f;
}
ll n,m,a[N],b[N],maxn=1;
void fun(ll x){
	if(a[x]-a[x-1]>m){
		return ;
	}
	ll l=1,r=x-1;
	while(l<r){
		ll mid=(l+r)/2;
		if((b[x-1]-b[mid-1]+m)>=((x-mid)*a[x])){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	maxn=max(maxn,x-l+1);
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		fun(i);
	}
	printf("%lld",maxn);
	return 0;
} 
