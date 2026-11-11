#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
long long n,ans,a,k;
vector<long long> v;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long j=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a;
		cin>>c;
		for(j=1;j<=a;j++)
			v.push_back(c-'a');
		k+=a;
	}
	for(long long i=0;i<k/2;i++)
	{
		k--;
		if(v[i]!=v[k])
		{
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}