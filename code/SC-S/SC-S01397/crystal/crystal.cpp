#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define maxn 1000005
#define SIZE 1<<14
using namespace std;
int read()
{
	int x=0,f=1,ac=getchar();
	if(ac=='-')f=-1;
	while(!isdigit(ac)){if(ac=='-')f=-1;ac=getchar();}
	while(isdigit(ac)){x=x*10+ac-'0',ac=getchar();}
	return x*f;
}
int buf[SIZE];
void write(int x,char ac,int f)
{
	if(x==0)putchar('0');
	if(x<0)x=-x,putchar('-');
	int p=0;
	while(x)buf[++p]=x%10,x/=10;
	for(int i=p;i>=1;i--)putchar(buf[i]+'0');
	if(f)putchar(ac);
}
int n,m,a[maxn],p,ax,pos1,pos2;
map<int,int>t;
bool check(int mid)
{
	if(mid<=t[p])return 1;
	int cnt=0;
	for(int i=1;i<=mid;i++)cnt+=a[mid]-a[i];
	return cnt<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	int ans=0,l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),t[a[i]]++;
		if(t[a[i]]>ax)ax=t[a[i]],p=a[i];
	}
	sort(a+1,a+1+n);
	pos1=lower_bound(a+1,a+1+n,p)-a,pos2=upper_bound(a+1,a+1+n,p)-a;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	write(ans,'\n',1);
	return 0;
}
// 4 6
// 1 3 8 9
// 2

// 9 1
// 1 1 1 1 1000 1001 1002 1003 1004
// 4
