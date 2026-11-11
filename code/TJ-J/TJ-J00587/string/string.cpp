#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll n,sum[MAXN];
struct node
{
	int a;
	char c;
}p[MAXN];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&p[i].a,&p[i].c);
		sum[i]=sum[i-1]+p[i].a;
		for(int j=1;j<=p[i].a;j++)
			s+=p[i].c;
	}
	int ans=0,len=s.length();
	for(int i=1;i<=len/2;i++)
	{
		if(s[len/2-i]!=s[len/2+i])
			ans++;
	}
	printf("%d",ans);
	return 0;
}
