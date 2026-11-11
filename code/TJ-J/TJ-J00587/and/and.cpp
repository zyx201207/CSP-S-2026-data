#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,m,a[MAXN];
int f1(int x)
{
	int ans=0;
	while(x>=1)
	{
		if(x%2==0)
			ans++;
		x/=2;
	}
	return ans;
}
string f2(int x)
{
	string ans="";
	while(x>=1)
	{
		char c=x%2+'0';
		ans=c+ans;
		x/=2;
	}
	return ans;
}
struct node
{
	int a;
	int x;//二进制位数 
	string s;
}p[MAXN];
bool cmp(node i,node j)
{
	if(i.x!=j.x)
		return i.x>j.x;
	for(int k=1;k<=i.x;k++)
		if(i.s[k]!=j.s[k])
			return i.s[k]>j.s[k];
	return true;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i].a);
		p[i].x=log2(p[i].a)+1;
		p[i].s=f2(p[i].a);
	}
	sort(p+1,p+n+1,cmp);
	int ans=p[1].a;
	for(int i=2;i<=m;i++)
		ans=ans&p[i].a;
	cout<<ans;
	return 0;
}
