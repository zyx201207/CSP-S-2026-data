#include<bits/stdC++.h>
#define int long long
using namespace std;
const int maxN=2e6+5;
int a[maxN];
int read()
{
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int kfjgh;
int n,d,t;
int spt(int s,int e)
{
	int tot=0;
	for(int i=s;i<=s+e-3;i++)
		if((a[e]-a[i]+1)%d==0)
			tot++;
	return tot;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	kfjgh=read(),t=read();
	while(t--)
	{
		
		n=read(),d=read();
		if(n<4)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		int sum=0;
		for(int i=1;i<=n-3;i++)
			for(int j=4;j<=n;j++)
				sum+=spt(i,j);
		cout<<sum<<endl;
	}
	return 0;
}
