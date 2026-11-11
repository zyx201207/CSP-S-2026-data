//Just Sayori
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<vector>
#include<random>
#define ll long long
#define ull unsigned long long
#define gr getchar
#define pr putchar
#define N 500005
#define M 1000000007
//#define M 998244353
//#define M 0x3f3f3f3f3f3f3f3f
#define for1(i,a,b) for(auto i=(a);i<=(b);i++)
#define for2(i,a,b) for(auto i=(a);i>=(b);i--)
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=gr();
	while (ch<'0' || ch>'9') ch=='-'?f=-1,ch=gr():ch=gr();
	while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=gr();
	return x*f;
}
inline int add(int a,int b,const int mod=M){return (a+=b)>=mod?a-mod:a;}
inline int del(int a,int b,const int mod=M){return (a-=b)<0?a+mod:a;}
template<typename T> inline bool chkmin(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline bool chkmax(T &a,T b){return a<b?a=b,1:0;}
int mx;
ll n,m;
ll a[N],sm[N];
bool chk(int l,int r)
{
	return (r-l+1)*a[r]-sm[r]+sm[l-1]<=m;
}
#define mid ((l+r)>>1)
int main()
{
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read(),mx=0;
	for1 (i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	for1 (i,1,n) sm[i]=sm[i-1]+a[i];
	for1 (i,1,n)
	{
		int l=1,r=i,k=i+1;
		while (l<=r)
		{
			if (chk(mid,i)) k=mid,r=mid-1;
			else l=mid+1;
		}
		chkmax(mx,i-k+1);
	}
	cout<<mx<<"\n";
	return 0;
}