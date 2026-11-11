#include<bits/stdc++.h>
using namespace std;
int a[100010];
char c[100010];
struct ustr
{
	long long be,en;
	char s;
}p[500010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long l=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int cnt=1;
	p[1].be=1;
	p[1].en=a[1];
	p[1].s=c[1];
	for(int i=2;i<=n;i++)
	{
		if(c[i-1]==c[i])
		{
			p[cnt].en+=a[i];
		}
		else
		{
			p[cnt+1].be=p[cnt].en+1;
			p[cnt+1].en=p[cnt+1].be+a[i]-1;
			p[++cnt].s=c[i];
		}
	}
	int ans=0;
	int le=1,li=1,ri=cnt;
	while(le<n/2+!(n%2))
	{
		if(p[li].s!=p[ri].s) ans+=min(p[li].en-p[li].be,p[ri].en-p[ri].be);
//		else if(p[li].en+p[ri].be!=(n+1)) ans+=abs(p[li].en+p[ri].be-n-1);
		else
		{
			le+=min(p[li].en-p[li].be,p[ri].en-p[ri].be);
			if(p[li].en>le) p[li].be=le;
			else li++;
			if(p[li].be<n+1-le) p[ri].en=n+1-le;
			else ri--;
		}
	}
	cout<<ans;
}

