#include<bits/stdc++.h>
using namespace std;
struct dd
{
	long long a;
	int b;
	int w;
}shu[1000005];
void bian(int n)
{
	int cnt=0,t=0;
	for(int i=1;i<=n;i++)
	{
		t=shu[i].a;
		while(t)
		{
			if(t%2==1)
			{
				shu[i].b++;
			}
			t/=2;
			shu[i].w++;
		}
	}
}
bool cmd(dd x,dd y)
{
	if(x.b!=y.b)
	{
		return x.b>y.b;
	}
	return x.w>y.w;
}
long long suan(long long x,long long y)
{
	long long sum=0;
	int cnt=0;
	while(min(x,y))
	{
		sum+=((x%2)&(y%2))*pow(2,cnt);
		cnt++;
		x>>=1;
		y>>=1;
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long ans,maxa=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>shu[i].a;
	}
	bian(n);
	sort(shu+1,shu+n+1,cmd);
	for(int i=1;i<=n-m;i++)
	{
		ans=shu[i].a;
		for(int j=i;j<i+m;j++)
		{
			ans=suan(ans,shu[j].a);
		}
		maxa=max(maxa,ans);
	}
	cout<<maxa<<endl;
	return 0;
}
