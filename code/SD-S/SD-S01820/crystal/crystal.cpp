#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll d=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	d=(d<<3)+(d<<1)+(ch^48),ch=getchar();
	return d*f;
}
ll n,m;
ll a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for (int i=1;i<=n;i++)
	a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	ll i,cnt=0;
	for (ll j=1;j<=n;j++)
	for (i=j+cnt;i<=n;i++)
	if((i-j)*a[i]-sum[i-1]+sum[j-1]>m){
		cnt=max(cnt,i-j);
		break;
	}
	printf("%lld",cnt);
}
