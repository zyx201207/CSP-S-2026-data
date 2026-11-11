#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define re register
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
const int N=5e5+2;
int n,a[N],sum[N],m,ans,pos=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(re int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n);
	for(re int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for(re int i=1;i<=n;++i){
		while((i-pos+1)*a[i]-(sum[i]-sum[pos-1])>m){
			pos++;
		}
		ans=max(ans,i-pos+1);
	}
	write(ans);
	return 0;
} 
