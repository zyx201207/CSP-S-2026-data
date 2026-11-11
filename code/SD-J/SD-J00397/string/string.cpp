#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
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
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
const int N=2e5+5;
int n,L,R,ans=0;
struct f{
	int num;
	char val;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(re int i=1;i<=n;++i){
		a[i].num=read();
		cin>>a[i].val;
	}
	L=1,R=n;
	while(L<R){
		int minn=min(a[L].num,a[R].num);
		a[L].num-=minn,a[R].num-=minn;
		if(a[L].val!=a[R].val){
			ans+=minn;
		}
		if(!a[L].num) L++;
		if(!a[R].num) R--;
	}
	write(ans);
	return 0;
}
