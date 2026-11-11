#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-48,ch=getchar();
	return ret*f;
}
const int maxn=2e5+5;
ll min(ll x,ll y){return x>y?y:x;}
ll l,r,ans;
int n;
ll a[maxn],c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		char ch=getchar();
		while('a'>ch||ch>'z')ch=getchar();
		c[i]=ch-'a';
	}
	for(int i=0,j=n+1;j-i>1;){
		if(l<=r){
			i++;
			if(c[j]!=c[i])ans+=min(r-l,a[i]);

			l+=a[i];
		}
		else{
			j--;
			if(c[j]!=c[i])ans+=min(l-r,a[j]);
			r+=a[j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}