#include<bits/stdc++.h>
using namespace std;
long long n,zhong=0,midle=0,ci=0,m1,m2,l;
struct nm
{
	long long shu;
	char zimu;
}cao[100100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>cao[i].shu>>cao[i].zimu;
		zhong+=cao[i].shu;
	}
	if(zhong%2==0)midle=zhong/2;
	else midle=zhong/2+1;
	int ji=0,k=0;
	for(int i=1;i<=n;i++)
	{
		ji=ji+cao[i].shu;
		if(ji>=midle)
		{
			if(ji>midle)m1=i,m2=i;
			else if(ji==midle)m1=i,m2=i+1,l=n;
			break;
		}	
	}
	for(int i=1;i<=m1;i++)k+=cao[i].shu;
	if(m1==m2)
	{
		for(int i=n;i>m1;i--)cao[i+1].shu=cao[i].shu,cao[i+1].zimu=cao[i].zimu;
		cao[m1+1].zimu=cao[m1].zimu,cao[m1+1].shu=k-midle,cao[m1].shu=cao[m1].shu-cao[m1+1].shu;
		l=n+1;
	}
	int zhuo,you;
	char zuo,yo;
	zuo=cao[m1].zimu,yo=cao[m2].zimu,zhuo=cao[m1].shu,you=cao[m2].shu;
	for(int i=m1,j=m2;i<=j,i>=1,j<=l;i--)
	{
		if(zuo!=yo)
		{
			if(zhuo<you)ci+=zhuo;
			else if(zhuo==you)ci+=zhuo;
			else if(zhuo>you)ci+=you;
		}
		if(zhuo<you)you-=zhuo,zhuo=cao[i-1].shu,zuo=cao[i-1].zimu;
		else if(zhuo==you)zhuo=cao[i-1].shu,zuo=cao[i-1].zimu,j++,you=cao[j].shu,yo=cao[j].zimu;
		else if(zhuo>you)zhuo-=you,j++,you=cao[j].shu,yo=cao[j].zimu;
	}
	cout<<ci;
	return 0;
}
