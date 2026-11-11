#include<iostream>
#include<cstdio>
using namespace std;

long long c,t,n,d,a[2000005];

long long read()
{
	int fs = 1;
	long long sum=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') fs=-1;
		c = getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum = sum*10+(c-'0');
		c = getchar();
	}
	return fs*sum;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++)
		{
			a[i] = read();
		}
		if(n<2) cout << 0 << endl;
		else if(2*(a[2]-a[1])>d) cout << 0 << endl;
		else
		{
			long long beishu = d/(a[2]-a[1]);
			beishu *= 2;
			long long t=n-beishu+1;
			if(t<0) t=0;
			cout << t << endl;
		}
	}
	return 0;
 } 
