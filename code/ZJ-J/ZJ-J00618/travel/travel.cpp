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
string a,b,c,d;bool ans[4];
#define isL(x) (x=='F'||x=='D')
void hxyt(){
	file(travel);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]=1;
		if(b.substr(0,2)==d.substr(0,2)){
			ans[1]=1;
			if(isL(b[2])==isL(d[2])){
				ans[2]=1;
				ans[3]=b[2]==d[2]+1||d[2]==b[2]+1;
			}
		}
	}
	printf("%d%d%d%d\n",ans[0],ans[1],ans[2],ans[3]);
}}signed main(){return hxyt1::hxyt(),0;}
