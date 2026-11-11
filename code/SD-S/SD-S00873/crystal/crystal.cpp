#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rd read()
int read(int u=0,bool f=false,char c=getchar()){
	for(;!isdigit(c);c=getchar()) f|=(c=='-');
	for(;isdigit(c);c=getchar()) u=(u<<1)+(u<<3)+(c^'0');
	return f?-u:u;
}void wt(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar((x%10)^'0');
}void wt(int x,char c){wt(x);putchar(c);}
const int N=5e5+10;
int n,m,a[N],sum[N],ans;
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd,m=rd;
	for(int i=1;i<=n;i++) a[i]=rd;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int l=1,i=1;i<=n;i++){
		while(a[i]*(i-l+1)-(sum[i]-sum[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}wt(ans,'\n');
	return 0;
} 
