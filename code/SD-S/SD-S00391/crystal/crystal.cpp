#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ss[500005],ans;
inline long long read()
{
	long long ifff=1,ix=0;
	char c=getchar();
	while('0'>c||c>'9')
	{
		if(c=='-')ifff*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')ix=ix*10+(c-'0'),c=getchar();
	return ifff*ix;
}
void pri(long long ox)
{
	if(ox<0)putchar('-'),ox=-ox;
	if(ox>9)pri(ox/10);
	putchar(ox%10+'0');
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)s[i]=a[n]-a[i],ss[i]=s[i]+ss[i+1];
	for(int r=1,l=1;r<=n&&l<=n;r++)
	{
		while(((ss[l]-ss[r+1]-(r-l+1)*s[r])>m)&&(l<=r))l++;
		if(l>r)continue;
		ans=max(r-l+1ll,ans);
	}
	pri(ans);
	return 0;
}
