#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n;
int m;
int a[N],s[N];
char tmp[100000],*p(0),*top(0);
//#define gtch()  (p==top&&(top=(p=tmp)+fread(tmp,1,100000,stdin)),*p++)
int read()
{
	int x;
	char c;
	bool f=0;
	while((c=getchar())<'0')  if(c=='-') {f=1;}
	x=c^'0';
	while((c=getchar())>='0') x=x*10+(c^'0');
	return f?(~x+1):x;
}
inline void print(int n)
{
	if(n<0){
		putchar('-');
		n*=-1;
	}
	if(n>9)  print(n/10);
	putchar(n%10+'0');
}
bool check(int k)
{
	int sum=0;
	return k*a[k]-s[k]<=m;
}
int pp(int k)
{
	int l=1,r=k,res;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if((k-mid+1)*a[k]-s[k]+s[mid-1]<=m)  res=mid,r=mid-1;
		else l=mid+1;
	}
	return k-res+1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    
	n=read(),m=read();
	int ans=0;
	for(int i=1;i<=n;i++)  a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)  s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))  ans=max(ans,mid),l=mid+1;
		else r=mid-1;
		//cout<<ans<<" ";
	}
	for(int i=ans+1;i<=n;i++)
	{
		ans=max(ans,pp(i));
	}
	print(ans);
} 
