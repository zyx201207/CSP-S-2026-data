#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int P=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10,M=2e6+10;
int n,a[N],i1,i2,y1,y2,ans=0;
char c[N];
void add(int y)
{
	if(c[i1]!=c[i2])
	ans+=y;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	i1=1;
	i2=n;
	y1=a[1],y2=a[n];
	while(i1<i2)
	{
		if(y1>y2)
		{
			y1-=y2;
			add(y2);
			i2--;
			y2=a[i2];
		}
		else if(y2>y1)
		{
			y2-=y1;
			add(y1);
			i1++;
			y1=a[i1];
		}
		else if(y1==y2)
		{
			add(y1);
			i1++;
			i2--;
			y1=a[i1];
			y2=a[i2];
		}
	}
	cout<<ans;
	return 0;
}

