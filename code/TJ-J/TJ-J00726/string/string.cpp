#include <bits/stdc++.h>
using namespace std;
struct aaa{
	long long a;
	char c;
};
int n,l,p;
aaa zz[1000000];
char s[1000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	    scanf("%lld%c",&zz[i].a,&zz[i].c);
	    for(int j=0;j<zz[i].a;j++)
    	{
		    s[l]==zz[i].c;
		    l++;
	    }
    }
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-1-i])
		p++;
	}
	cout<<p;
	return 0;
}
