#include<bits/stdc++.h>
using namespace std;

int n,m;
long long sum,cnt;
char s[1000005];
struct Z
{
	int a;
	char c;
	long long q,r;
}z[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=1;
	for(int i=1;i<=n;i++)
	{
		cin>>z[i].a>>z[i].c;
		for(int j=l;j<l+z[i].a;j++)
			s[j]=z[i].c;
		z[i].q=l;
		l+=z[i].a;
		z[i].r=l-1;
	}
	if(l>10000000)
	{
		if(z[1].c!=z[n].c)
			for(int i=1;i<=n;i++)
				if(z[i].q<l/2&&z[i].r>l/2)
					cout<<min(z[i].q-1,l-z[i].r);
	}
	for(long long i=1,j=l-1;i<=j;i++,j-- )
	{
		if(s[i]!=s[j])
			cnt++;	
	}
	cout<<cnt;	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
