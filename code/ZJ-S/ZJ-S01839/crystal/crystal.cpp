#include<bits/stdc++.h>
using namespace std;
const int MA=500005;
#define int long long
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int m,n;
int a[MA],sum[MA];
signed main()
{
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
	bool is=false;
	int l=1,r=n,mid=(l+r+1)/2;
	while(l<r){
		is=false;
		mid=(r+l+1)/2;
		for(int i=1;i<=n-mid+1;i++){
			if(a[mid+i-1]*mid-(sum[mid+i-1]-sum[i-1])<=m){
				is=true;
				break;
			}
		}
		if(!is){
			r=mid-1;
		}
		else l=mid;
	}
	printf("%lld",l);
}