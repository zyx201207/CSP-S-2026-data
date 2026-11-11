#include<bits/stdc++.h>
using namespace std;
long long n,m,md,sum,amd,anss;
long long a[500010],cha[500010],ca[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==1)
		md=n/2+1;
	else
	    md=n/2;
	amd=a[md];
	for(int i=1;i<=md;i++)
	{
		if(i==md)
		{
			cha[i]=0x3f3f3f;
		}
		cha[i]=abs(a[i]-amd);
	}
	sort(cha+1,cha+md+1);
	long long mt=m;
	for(int i=1;i<md;i++)
	{
		if(mt>=cha[i])
		{
			mt-=cha[i];
			anss++;
		}
		else
		    break;
	}
	cout<<anss+1;
	return 0;
}
