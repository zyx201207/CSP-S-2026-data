#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],l,r,mid,maxn=0,tmp1=0,tmp2=0,sum=0,speciall,cnt,h;
bool flag=true;
bool cmp(int i,int j)
{
	return i<j;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	speciall=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=speciall)
		{
			flag=false;
		}
	}
	h=a[1]-speciall;
	if(flag==true)
	{
		cnt=0;
		while(sum<=m&&cnt<=n)
		{
			cnt++;
			sum+=a[cnt]-h;
			
		} 
		cout<<cnt<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	maxn=a[n];
	for(int i=1;i<=n;i++)
	{
		sum+=(maxn-a[i]);
	}
	l=1,r=n;
	while(l<=r&&n!=0)
	{
		maxn=a[r];
		if(sum<=m)
		{
			break;
		}
		tmp1=maxn-a[l];
		tmp2=(maxn-a[n-1])*(n-1);
		if(tmp1<=tmp2)
		{
			r--;
			sum-=tmp2;
		}
		else
		{
			l++;
			sum-=tmp1;
		}
		n--;
	}
	cout<<n;
	return 0;
}
