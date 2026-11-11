#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	double c1,c2,s1,s2;
	double a[4];
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		a[1]=1;
	}
	else
	{
		a[1]=0;
	}
	if(s1[1]==s2[1] and s1[2]==s2[2])
	{
		a[2]=1;
	}
	else
	{
		a[2]=0;
	}
	if ((('s1[3]'=='A' or 's1[3]'=='B' or 's1[3]'=='C') and ('s2[3]'!='D' and 's2[3]'!='F')) and (('s2[3]'=='A' or 's2[3]'=='B' or 's2[3]'=='C') and ('s1[3]'!='D' and 's1[3]'!='F')) and  (('s1[3]'!='A' and 's1[3]'!='B' and 's1[3]'!='C') and ('s2[3]'=='D' or 's2[3]'=='F')) and (('s2[3]'!='A' and 's2[3]'!='B' and 's2[3]'!='C') and ('s1[3]'=='D' or 's1[3]'=='F')))
	{
		a[3]=1;
	}
	else
	{
		a[3]=0;
	}
	if((('s1[3]'+1)=='s2[3]' or ('s2[3]'+1)=='s1[3]') and (('s1[3]'=='C' and 's2[3]'!='D') or ('s1[3]'=='D' and 's2[3]'!='C')))
	{
		a[4]=1;
	}
	else
	{
		a[4]=0;
	}
	cout<<a;
	return 0;
} 
