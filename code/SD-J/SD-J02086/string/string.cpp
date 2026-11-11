#include<bits/stdc++.h>
using namespace std;
long long n,t;
char a[10000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%ll",&n);
	long long l=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		long long c;
		char s;
		scanf("%ll%c",&c,&s);
		for(long long j=l;j<=l+c-1;j++) a[j]=s;
		l=l+c;
		ans+=c;
	}
	for(long long i=1;i<=ans/2;i++)
	{
		if(a[i]!=a[ans+1-i]) t++;
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
