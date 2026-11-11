#include<bits/stdc++.h>
namespace hxyt1{
using namespace std;
//#define int ll
#define ll long long
#define U unsigned
#define file(s) freopen(#s ".in","r",stdin),freopen(#s  ".out","w",stdout)
#define rad read<int>
#define gc getchar
template<class T>T read(){char c;bool f=0;T x=0;for(;!isdigit(c=gc());f|=c=='-');for(;isdigit(c);x=x*10+c-48,c=gc());return f?-x:x;}
const int N=2e5+5;int n,m,a[N],ans;
void hxyt(){
	file(and);
	n=rad(),m=rad();
	for(int i=1;i<=n;i++)a[i]=rad();
	for(int x=1<<30;x;x>>=1){
		int cnt=0;
		for(int i=1;i<=n;i++)if(a[i]&x)cnt++;
		if(cnt>=m){
			ans|=x;
			for(int i=1;i<=n;i++)if((a[i]&x)==0)a[i]=0;
		}
	}
	printf("%d\n",ans);
}}signed main(){return hxyt1::hxyt(),0;}

