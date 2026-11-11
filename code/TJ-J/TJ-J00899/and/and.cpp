#include<bits/stdc++.h>
using namespace std;
struct num
{
	int c1;
	int c0;
};
int b1(int a)
{
	int cnt1;
	while(a>0)
	{
		if(a%2==1)
			cnt1++;

		a/=2;
	}
	return cnt1;
}
int b0(int a)
{
	int cnt0;
	while(a>0)
	{
		if(a%2==0)
			cnt0++;
		a/=2;
	}
	return cnt0;
}
bool cmp(int a,int b)
{
	if(a>b)
		return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	num nn[n];
	for(int i=0;i<n;i++)
	{
		int n1;
		cin>>n1;
		nn[i].c1=b1(n1);
		nn[i].c0=b0(n1);
		sort(nn.c1(),nn.c1()+1+n,cmp);
		sort(nn.c0(),nn.c0()+1+n,cmp);
	}
	int max0,max1;
	for(int i=0;i<m-1;i++)
	{
		max1=nn[i].c1&&nn[i+1].c1;
	}
	
	
	for(int i=0;i<m-1;i++)
	{
		max0=nn[i].c0&&nn[i+1].c0;
	}
	cout<<max(max0,max1);
	
	
	
	
	return 0;
}
