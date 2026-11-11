#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int l;
	char d;
}a[200010];
long long ans,cnt=1,cnt1;
int main()
{
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c", &a[i].l, &a[i].d);
		cnt1+=a[i].l;
	}
	char x[cnt1+1];
	for(int i=1;i<=n;i++)
	{
		while(a[i].l--)
		{
			x[cnt++]=a[i].d;
		}
	}
	cnt/=2;
	for(int i=1;i<=cnt;i++)
	{
		if(x[i]!=x[n-i+1])
		{
			ans++;
		}
	}
	printf("%d",ans);
  return 0;
}