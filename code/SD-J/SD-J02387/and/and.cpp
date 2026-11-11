#include<bits/stdc++.h>
using namespace std;
long long mp[35]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870912};
long long a[200005],b[200005];
//long long tw(long long x)
//{
//	int v=0;
//	for(int i=1;i<=30;++i)
//	{
//		if(mp[i]>x)
//		{
//			v=i-1;
//			break;
//		} 
//	}
//	long long ans=0;
//	while(x!=0)
//	{
//		if(x-v>=0) 
//		{
//			ans+=pow(10,v);
//		}
//		--v; 
//	}
//	return ans;
//}
int main()
{
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	if(m==1) 
	{
		cout<<b[n];
		return 0;//5 points
	}
	bool flag,flagg=true;
//	int val=0;
//	for(int i=1;i<=30;++i)
//	{
//		if(b[i]==mp[i])
//		{
//			flag=true;
//			val=i;
//			break;
//		} 
//	}
	if(flag)
	{
		for(int i=n;i>=n-m;--i)
		{
			if(b[i]!=mp[i]) flagg=false;
		}
	}
	if(flagg) 
	{
		cout<<b[n-m];//5 points
		return 0;
	}
	return 0;
}
//10 points !Lao_ying da gou fen xiao dai ma 
