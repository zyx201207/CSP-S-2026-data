#include<bits/stdc++.h>
using namespace std;
#ifdef __unix
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
template<typename T>
inline bool read(T &x){
	x=0;bool f=0;int c=gc();
	for(;!isdigit(c);c=getchar()){
		if(!(~c)) return 0;
		if(c=='-') f=1;
	}
	for(;isdigit(c);c=gc()){
		x=(x<<3)+(x<<1)+(c^'0');
	}
	return x=f?-x:x,1;
}
template<typename A,typename...B>
int read(A &x,B&...y){
	return read(x)+read(y...);
}
inline void Write(char c){
	pc(c);
}
inline void Write(const char *a){
	int len=strlen(a);
	for(int i=0;i<len;++i) pc(a[i]);
}
template<typename T>
void Write(T x){
	if(x<0) x=-x;
	if(x<10) return pc(x^'0'),void(0);
	Write(x/10),pc((x%10)^48);
}
inline int write(){return 0;}
template<typename A,typename...B>
int write(A x,B ...y){
	Write(x);
	return write(y...)+1;
}
#define int long long
#define Freopen
#define N 500010
//#define DEBUG
int n,m,a[N],ans,id(1),sum(1),f[N];
inline void gmax(int &a,int b){if(a<b) a=b;}
signed main(){
	#ifdef Freopen
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	read(n,m);
	for(int i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i){
		int val=a[i]-a[i-1];
		if(m>=val*(i-id)){
			++sum;
			m-=val*(i-id);
		}
		else{
			gmax(ans,sum);
			while(m<val*(i-id)){
				m+=a[i-1]-a[id];
				++id;
				--sum;
			}
			if(id!=i){
				m-=val*(i-id);
				++sum;
			}
		}
	}
	gmax(ans,sum);
	write(ans);
	return 0;
}
