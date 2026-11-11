#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
template<typename T>inline void read(T &x){
	bool f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=(f?-x:x);return;
} 
//template<typename T,typename ...Args>inline void read(T &x,Args &...x_){
//	read(x),read(x_...);
//}
template<typename T>inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');return;
}
const int N=5e5+10;
int n,m,ans=1;
long long a[N],s[N],d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	register int i,j;
	read(n);read(m);
	for(i=1;i<=n;i=-~i) read(a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i=-~i) s[i]=a[i]-a[i-1];
	for(i=1,j=1;i<=n;i=-~i){
		d+=(i-j)*s[i];
		while(j<i&&d>m){
			d-=(a[i]-a[j]);
			j=-~j;
		}
		ans=max(ans,i-j+1);
	}
	write(ans);
	return 0;
}
