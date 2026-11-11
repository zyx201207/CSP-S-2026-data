#include<bits/stdc++.h>
using namespace std;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char buf[1<<20],*p1,*p2;
template<typename T> inline void read(T& x){
	x=0;int f=1;char c=gc();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=gc();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=gc();
	}
	x*=f;
}
template<typename T> inline void print(T x){
	if(x>9){
		print(x/10);
	}
	putchar(x%10^48);
}
int n,l,r,md,ans;
long long m,a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		l=1,r=i;
		while(l<=r){
			md=l+r>>1;
			if((i-md+1)*a[i]-(s[i]-s[md-1])<=m){
				r=md-1;
				ans=max(ans,i-md+1);	
			}else{
				l=md+1;
			}
		}
	}
	print(ans);
	return 0;
}