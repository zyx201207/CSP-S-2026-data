#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-48,ch=getchar();
	return ret*f;
}
const int maxn=5e5+5;
ll n,m,ans;
ll a[maxn],s[maxn];
inline ll max(ll x,ll y){return x>y?x:y;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&s[j+1]-s[i-1]+m>=a[j+1]*(j-i+2))j++;
		ans=max(ans,j-i+1);
	}
	printf("%lld\n",ans);
	return 0;
}