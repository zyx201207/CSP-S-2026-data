#include<bits/stdc++.h>
#define int long long
#define db double
#define endl "\n"
using namespace std;
const int N=500010;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m;
int sum;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int cnt=0,t=m;
		for(int j=i;j>=1;j--)
		{
			t=t-(a[i]-a[j]);
			if(t<0) break;
			cnt++;
		}
		sum=max(cnt,sum);
	}
	cout<<sum<<endl;
	return 0;
}
