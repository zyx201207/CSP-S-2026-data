#include<bits/stdc++.h>
using namespace std;
struct s
{
	long long z;
	string y;
}a[200010];
string pd(long long a)
{
	string temp="",ans="";
	while(a>0)
	{
		if(a%2==1)
		{
			temp+='1';
		}
		else
		{
			temp+='0';
		}
		a/=2;
	}
	long long l=temp.length();
	for(long long i=0;i<l;i++)
	{
		ans+=temp[l-i-1];
	}
	return ans;
}
bool cmp(s f,s g)
{
	return f.y>g.y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].z);
		a[i].y=pd(a[i].z);
	}
	sort(a+1,a+1+n,cmp);
	long long ans=a[1].z;
	for(long long i=2;i<=m;i++)
	{
		ans&=a[i].z;
	}
	printf("%lld",ans);
    return 0;
}
