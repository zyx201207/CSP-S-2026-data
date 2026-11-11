#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked
#define pc putchar_unlocked
int a[500005];
int s[500005];
void read(int& x)
{
	x=0;
	bool flg=0;
	char ch=gc();
	while(ch<'0' ||  ch>'9') 
	{
		if(ch=='-') flg=1;
		ch=gc();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0';
		ch=gc();
	}
	if(flg) x=-x;
}
void write(int x)
{
	if(x>=10) write(x/10);
	pc(x%10+'0');
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	read(n);read(m);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,qwq=i;
		s[i]=s[i-1]+a[i];
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid-1,qwq=mid;
			else l=mid+1;
		}
		ans=max(ans,i-qwq+1);
		//if(i-qwq+1==4702) cout<<a[i]*i-s[i]<<" "<<m<<"\n";
	}
	write(ans);
	return 0;
}
