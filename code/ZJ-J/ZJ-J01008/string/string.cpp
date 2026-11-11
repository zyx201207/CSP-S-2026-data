#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long x,y;
	char s;
}a[200009];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	a[0].y=0;
	long long len=0;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char c[5];
		scanf("%lld%s",&x,c+1);
		a[i].x=a[i-1].y+1;
		a[i].y=a[i].x+x-1;
		a[i].s=c[1];
		len+=x;
	}
	long long ans=0;
	int last=1,next=n;
	for(long long i=1;i<=(len+1)/2;i++)
	{
		char v,u;
		if(i>=a[last].x && i<=a[last].y) v=a[last].s;
		else last++,v=a[last].s;
		if(len-i+1>=a[next].x && len-i+1<=a[next].y) u=a[next].s;
		else next--,u=a[next].s;
		if(v!=u) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}