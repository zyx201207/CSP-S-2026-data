#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
namespace ly{
	namespace IO{
		#define SIZE (1<<20)
		char in[SIZE],out[SIZE],*p1=in,*p2=in,*p3=out;
		#define getchar() (p1==p2&&(p2=(p1=in)+fread(in,1,SIZE,stdin),p1==p2)?EOF:*p1++)
		#define flush() (fwrite(out,1,p3-out,stdout),p3=out)
		#define putchar(ch) (p3==out+SIZE&&flush(),*p3++=(ch))
		class Flush {
			public:~Flush() {
				flush();
			}
		}_;
		template<typename T>
		inline void read(T&x) {
			x=0;bool flag=0;char ch=getchar();
			while (!isdigit(ch)) flag=ch=='-',ch=getchar();
			while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
			flag?x=-x:0;
		}
		template<typename T>
		inline void write(T x,bool flag=0) {
			x<0?x=-x,putchar('-'):0;
			static short Stack[105],top;top=0;
			do Stack[++top]=x%10,x/=10;while (x);
			while (top) putchar(Stack[top--]|48);
			flag?putchar('\n'):putchar(' ');
		}
		#undef SIZE
		#undef getchar
		#undef putchar
		#undef flush 
	}
}using namespace ly::IO;
typedef long long ll;
ll n,m;
ll a[500005],s[500005];
bool is_13_to_18=true,is_1_to_9=true;
void solve_1_to_9() { //n<=5000
	ll maxn=0;
	for (int i=1;i<=n;i++) {
		ll sum=0;
		for (int j=1;j<i;j++) {
			sum+=a[i]-a[j];
		}
		if (sum<=m) {
			maxn=max(maxn,ll(i));
		}
	}
	write(maxn);
	return;
}
void solve_13_to_18() { //n>5000 a为等差数列 
	ll maxn=0;
	for (int i=1;i<=n;i++) {
		ll start=0,end=a[i]-a[1],diff=a[2]-a[1];
		ll len;
		if (diff==0) {
			len=i;
		}else len=(end-start)/diff+1;
		ll sum=(start+end)*len/2;
		if (sum<=m) {
			maxn=max(maxn,ll(i));
		}
	}
	write(maxn);
	return;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	if (n>5000) is_1_to_9=false;
	for (int i=1;i<=n;i++) {
		if (a[i]-a[i-1]!=a[2]-a[1]){
			is_13_to_18=false;
		}
	}
	if (is_1_to_9) {
		solve_1_to_9();
	} else if (is_13_to_18) {
		solve_13_to_18();
	} else {
		solve_1_to_9();
	}
	return 0;
}
