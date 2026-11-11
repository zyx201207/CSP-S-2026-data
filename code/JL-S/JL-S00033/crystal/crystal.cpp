#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
bool  deng(int x,int y)
{
	if(x==y) return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,kuai=0,d=0;
	bool l=false;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		if(deng(a[i],a[i+1])||deng(a[i],a[i-1]))
		{
			kuai=2;
			l=true;
		}
	}
	for(int i=1;i<=n/2;i++)
	{
		int k=a[n/2+i]-a[n/2+1-i],kk=a[n/2+i+1]-a[n/2+i];
	if(k<=m&&k<=kk)
	{
		d++;
		if(d==1&&l==false)
		{
			kuai+=2;
		}
		else
		{
			kuai++;
		}
		m=m-k;
	}
	if(kk<=m&&kk<=k)
	{
		d++;
		if(d==1&&l==false)
		{
			kuai+=2;
		}
		else
		{
			kuai++;
		}
		m=m-k;
	}
}
	cout<<kuai;
	return 0;
}
