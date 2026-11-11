#include<bits/stdc++.h>
using namespace std;namespace hxyt1{
//#define int ll
#define ll long long
#define U unsigned
#define file(s) freopen(#s ".in","r",stdin),freopen(#s ".out","w",stdout)
#define rad read<int>
#define gc getchar
template<class T>T read(){char c;bool f=0;T x=0;for(;!isdigit(c=gc());f|=c=='-');for(;isdigit(c);x=x*10+c-48,c=gc());return f?-x:x;}
const int N=5e5+5;int n,ans;ll a[N],m;
int find(int i){
	int l=1,r=i,res=INT_MAX;
	for(int mid;l<=r;){
		mid=(l+r)/2;
		if((a[i]-a[i-1])*(i-mid+1)-a[i]+a[mid-1]<=m)res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
void hxyt(){
	file(crystal);
	n=rad(),m=read<ll>();
	for(int i=1;i<=n;i++)a[i]=read<ll>();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=n;i++)ans=max(ans,i-find(i)+1);
	printf("%d\n",ans);
}}signed main(){return hxyt1::hxyt(),0;}

