#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,i,j,m,flag=0,s1=0,s2=0,s3=0,s0=0,maxx=-1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==3) 
		{
			s3++;
		}
		if(a[i]==2)
		{
			s2++;
		}
		if(a[i]==1)
		{
			s1++;
		 }
		 if(a[i]==0)
		 {
		 	s0++;
		 }
		if(a[i]>=4)
		{
			flag=1;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	if(m==2)
	{
		for(i=1;i<=n-1;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				maxx=max((a[i]&a[j]),maxx);
			}
		}
		cout<<maxx;
		return 0;
	}
	
	if(flag==0)
	{
		if(s3>=m) cout<<3;
		else if(m<=(s3+s2)) cout<<2;
		else if(m<=(s3+s2+s1)) cout<<1;
		else if(m<=(s3+s2+s1+s0)) cout<<0;
	}
	else
	{
		cout<<a[m];
	}
	return 0;
}

