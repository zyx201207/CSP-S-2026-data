#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
long long n,a,b[MAXN],lb=0;
char c[2],d[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a>>c[0];
	b[++lb]=a;
	d[lb]=c[0];
	for(int i=2;i<=n;i++)
	{
		cin>>a>>c[1];
		if(c[1]==c[0]) b[lb]+=a;
		else
		{
			b[++lb]=a;
			d[lb]=c[1];
		}
		c[0]=c[1];
	}
	if(lb==1)
	{
		cout<<0;
		return 0;
	}
	long long m1=0,m2=0;
	for(int i=1;i<lb;i++) m1+=b[i];
	for(int i=2;i<=lb;i++) m2+=b[i];
	cout<<min(m1,m2);
	return 0;
}