#include<bits/stdc++.h>
using namespace std;
#define file(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define int ll
#define ll long long
#define rad read<int>
#define gc getchar
template<typename T>T read(){
	T ret=0;bool f=0;char ch;
	for(;!isdigit(ch=gc());f=!f?(ch=='-'):f);
	for(;isdigit(ch);ch=gc())ret=(ret<<3)+(ret<<1)+(ch^48);
	return f?-ret:ret;
}
#define maxn 2000005
int c,n,m,d,q,ans,cnt,x[maxn],jl;

signed main(){
	file(subway);
	c=rad(),n=rad(),m=rad(),d=rad(),q=rad();
	while(q--)printf("%d\n",d);
	return 0;
}
