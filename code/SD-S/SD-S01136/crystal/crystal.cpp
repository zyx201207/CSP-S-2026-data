#include<bits/stdc++.h>
#define ll long long
#define N 500100
using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
ll n,m,l,r,p,ans,a[N],s[N];
bool check(int x,int i){ 
	return a[i]*(i-x+1)-(s[i]-s[x-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;++i){
		l=1,r=i-1,p=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(mid,i))p=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans<<"\n";
	return 0;
}
