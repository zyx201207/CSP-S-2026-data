#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
	long long a,l,r;
	char c;
}b[200010],d[200010];
long long ret,len;
int main()
{
	//freopen("string6.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&b[i].a,&b[i].c);
		len+=b[i].a;
		d[n-i+1].a=b[i].a;
		d[n-i+1].c=b[i].c;
	}
	for(int i=1;i<=n;i++)
	{
		b[i].l=b[i-1].r+1;
		b[i].r=b[i].l+b[i].a-1;
		d[i].l=d[i-1].r+1;
		d[i].r=d[i].l+d[i].a-1;
	}
	int r2=1;
	long long ret=0;
	for(int i=1;i<=n;i++)
	{
		long long l=b[i].l,r=b[i].r;
		while(r2<=n&&d[r2].r<=r)
		{
			if(d[r2].c!=b[i].c)
			{
				ret+=max(0ll,(min(d[r2].r,r)-max(l,d[r2].l)+1));
			}
			r2++;
		}
		if(r2<=n&&d[r2].c!=b[i].c)
		{
			ret+=max(0ll,(min(d[r2].r,r)-max(l,d[r2].l)+1));
		}
	}
	cout<<ret/2;
	return 0;
}
