#include<bits/stdc++.h>
#define ll long long
#define rd read()
using namespace std;
const int N = 5e5 + 10;
ll n,a[N],d[N],ans,l=1,r=0,m;
inline ll read(){
	ll x=0,f=1,ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
inline void wt(ll x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wt(x/10),x%=10;
	putchar(x+48);
}
inline void wtln(ll x){
	wt(x),putchar('\n');
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd,m=rd;
	for(int i=1;i<=n;i++)a[i]=rd;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
	ll s=0;
	for(int i=1;i<n;i++){
		r++;
		s+=(r-l+1)*d[i];
		while(s>m)s-=(a[i+1]-a[l]),l++;
		ans=max(ans,r-l+1);
	}
	wtln(ans+1);
	return 0;
}