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
const int N=5e5+5,M=3e5+5;int n,m,cnt[M],a[N],stk[N];bool lst[M];
void hxyt(){
	file(card);
	n=rad(),m=rad();
	for(int i=1;i<=n;i++)a[i]=rad();
	for(int _=1;_<=n;_++){
		*stk=0;
		memset(lst,0,sizeof lst);
		for(int i=_;i<=n;i++){
			if(lst[a[i]]){
				do{
					cnt[stk[*stk]]--;
					lst[stk[*stk]]=0;
					--*stk;
				}while(stk[*stk+1]!=a[i]);
			}
			cnt[a[i]]++;
			lst[a[i]]=1;
			stk[++*stk]=a[i];
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
}}signed main(){return hxyt1::hxyt(),0;}

