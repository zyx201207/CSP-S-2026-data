#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read();
const int N=5e5+10;
ll n,m,a[N],d[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	ll mx=1,l=1;
	for(ll r=1;r<=n;r++){
		ll sum=0;
		while(a[r]*(r-l+1)-(pre[r]-pre[l-1])>m)l++;
		mx=max(mx,r-l+1);
	}cout<<mx<<'\n';
	return 0;
}
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}

