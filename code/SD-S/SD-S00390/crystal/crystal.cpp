#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=5e5+50;

int inline read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

ll n,m;
ll a[maxn];
ll sum[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read();m=read();
	
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	
	ll ans=-1;
	ll l=1,r=1;
	while(r<=n){
		while(l>=r)r++;
		while((r-l+1)*a[r]-sum[r]+sum[l-1]>m)l++;
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
