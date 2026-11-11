#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500050],sum[500050],ans;
ll read(){
	ll _a=0,_ne=1;
	char _c=getchar();
	while(!isdigit(_c)){
		if(_c=='-')_ne=-1;
		_c=getchar();
	}
	while(isdigit(_c)){
		_a=(_a<<3)+(_a<<1)+(_c^48);
		_c=getchar();
	}
	return _a*_ne;
}
void write(ll _a){
	if(_a<0){
		putchar('-');
		_a=-_a;
	}
	if(_a>9)write(_a/10);
	putchar(_a%10+'0');
}
bool ck(ll x){
	for(int i=1;i+x-1<=n;i++){
		if(a[i+x-1]*x-(sum[i+x-1]-sum[i-1])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,mid,r=n;
	while(l<=r){
		mid=l+r>>1;
		if(ck(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	write(ans);
	return 0;
}
