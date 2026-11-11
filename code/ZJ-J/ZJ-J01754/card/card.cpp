#include<bits/stdc++.h>
using namespace std;
long long n,m,s[100005],sd[200005],c[10005],f;
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	scanf("%lld %lld",n,m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",sd[i]);
	
		c[i]=sd[i];
		s[sd[i]]++;
		if(s[sd[i]]%2==0)
		{
			f=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",s[i]);
	}
}
