#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long answer,a[N];
bool cmp(long long x,long long y)
{
	int tx=x,ty=y,cntx=0,cnty=0;
	while(x>0)
	{
		if(x%2==1)
		{
			cntx++;
		}
		x/=2;
	}
	while(y>0)
	{
		if(y%2==1)
		{
			cnty++;
		}
		y/=2;
	}
	if(cntx==cnty)
	{
		return tx>ty;
	}
	return cntx>cnty;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	answer=a[1];
	for(int i=1;i<=m;i++)
	{
		answer&=a[i];
	}
	cout<<answer<<endl;
	return 0;
}
