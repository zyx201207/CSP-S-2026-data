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
const int N=2e5+5;int n;ll ans,cnti,cntj;
struct Str{
	int x;char c;
}s[N];
void hxyt(){
	file(string);
	n=rad();
	for(int i=1;i<=n;i++){
		s[i].x=rad();char c;
		for(;!islower(c=gc()););
		s[i].c=c;
	}
	for(int i=1,j=n;i<j;i++){
		cnti+=s[i].x;
		for(;i<j;j--){
			if(cntj+s[j].x>=cnti){
				s[j].x-=cnti-cntj;
				if(s[j].c!=s[i].c)ans+=cnti-cntj;
				cntj=cnti;
				break;
			}
			cntj+=s[j].x;
			if(s[j].c!=s[i].c)ans+=s[j].x;
		}
	}
	printf("%lld\n",ans);
}}signed main(){return hxyt1::hxyt(),0;}

