#include<bits/stdc++.h>
#define int long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define ROF(i,r,l) for(int i=r;i>=l;i--)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define all(x) x.begin(),x.end()
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int N=5e5+10;
int a[N],s[N];
int calc(int l, int r){
	return a[r]*(r-l+1)-s[r]+s[l-1];	
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read();
	FOR(i,1,n)a[i] =read();
	sort(a+1,a+n+1);
	FOR(i,1,n)s[i]=s[i-1]+a[i]; 
	int l=1,ans=0;
	FOR(r,1,n){
		while(calc(l,r)>m)l++;
		cmax(ans,r-l+1); 
	}
	cout<<ans<<"\n";
	return 0;
}

