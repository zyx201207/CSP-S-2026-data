#include<bits/stdc++.h>
using namespace std;
#define N 200005
struct f
{
	int k,t;
	long long num;
}a[N];
bool cmp(f x,f y)
{
	if(x.t!=y.t)return x.t>y.t;
	else
		return x.k<y.k;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long sum=pow(2,31)-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].num;
	for(int i=1;i<=n;i++)
	{
		int t=0,k,tn=a[i].num;
		while(tn)
		{
			tn>>=1;
			t++;
		}
		if(a[i].num==0)
		{
			a[i].t=0;
			a[i].k=0;
		}
		else
		{
			k=min(pow(2,t)-a[i].num,a[i].num-pow(2,t-1));
			t=pow(2,t+1)-a[i].num>a[i].num-pow(2,t)?t:t+1;
		}
		a[i].k=k;
		a[i].t=t;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		sum=sum&a[i].num;
	}
	cout<<sum<<'\n';
	return 0;
}
