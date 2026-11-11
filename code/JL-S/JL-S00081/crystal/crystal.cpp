#include<bits/stdc++.h>
using namespace std;
long long a[500010],c[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,cnt=2,minn=1e9,minx=0,sum=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(long long i=0;i<n-1;i++)
	{
		c[i]=a[i+1]-a[i];
		if(c[i]<minn)
		{
			minn=c[i];
			minx=i;
		}
	}
	if(minn>=m){
		 cout<<1;
		 return 0;
	}
	m-=minn;
	
	if(minx==0)
	{
		for(long long i=1;i<n-1;i++)
		{
			if((m>=0)&&(m>=c[i]))
			{
				sum=sum+c[i];
				m-=sum;
				cnt++;
			}
			else 
				break;
		}
	}
	else if(minx==n-1)
	{
		for(long long i=minx-1;i>=0;i--)
		{
			if((m>=0)&&(m>=c[i]))
			{
				sum=sum+c[i];
				m-=sum;
				cnt++;
			}
			else 
				break;
		}
	}
	else if(c[minx-1]<c[minx+1])
	{
		for(long long i=minx-1;i>=0;i--)
		{
			if((m>=0)&&(m>=c[i]))
			{
				sum=sum+c[i];
				m-=sum;
				cnt++;
			}
			else 
				break;
		}
	}
	else if(c[minx-1]>c[minx+1])
	{
		for(long long i=minx+1;i<n-1;i++)
		{
			if((m>=0)&&(m>=c[i]))
			{
				sum=sum+c[i];
				m-=sum;
				cnt++;
			}
			else 
				break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
