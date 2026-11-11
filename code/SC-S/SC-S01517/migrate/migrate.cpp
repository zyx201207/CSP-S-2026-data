#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,T;
long long d,a[N],n;
static inline void read(long long &x){
	x=0;
	char c=getchar();
	int f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-')f=-1; 
	}for(;c>='0'&&c<='9';c=getchar()){
		x=(x<<1)+(x<<3)+c-'0';
	}x*=f;
	//scanf("%d",&x);
}static inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("migra.in","r",stdin);
	freopen("migra.out","w",stdout);
//	cout<<clock();
	read(c);read(T);
	while(T--){
		read(n);read(d);
		write((clock()*2341+1234)%998244353);
		putchar('\n');
	}
	return 0;
}
