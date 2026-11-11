#include <bits/stdc++.h>
using namespace std;
struct str
{
	char a;
	long long m;
}s[200005];
int main() {
	int n,i,k=0,m;
	long long sum=0;
	char a;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s[i].m;
		cin>>s[i].a;
	}
	int p=1,q=n;
	while(p<q)
	{
		if(s[p].a!=s[q].a)
		{
			sum+=min(s[p].m,s[q].m);
			s[p].m-=s[q].m;
			s[q].m-=s[p].m;
		}
		else if(s[p].a==s[q].a)
		{
			s[p].m=0;
			s[q].m=0;
		}
		if(s[p].m<=0) p++;
		if(s[q].m<=0) q--;
	}
	cout<<sum;
	return 0;
}
