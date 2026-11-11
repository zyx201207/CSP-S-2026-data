#include<bits/stdc++.h>
using namespace std;
int n;
long long int a[200100];
int m;
long long int maxx=INT_MIN;
long long int solve1(int n,int m)
{
	for(long long int i=1;i<=2^n;i++)
	{
		int k=0;
		long long int sum;
		bool f=0;
		for(long long int j=0;j<i;j++)
		{
			if(i&(1<<j)&&f==0){
				sum=a[j+1];
				f=1;
				k++;
			}
			if(i&1<<j&&f==1)
			{
				sum=sum&a[j+1];
				k++;
			}
		}
		if(k!=m) continue;
		maxx=max(maxx,sum);
	}
	return maxx;
}
long long int solve2(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}
	return maxx;
}
long long int solve3(int n)
{
	long long int sum2;
	sum2=a[1];
	for(int i=1;i<=n;i++)
	{
		sum2&=a[i]; 
	}
	return sum2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long int max1=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	if(m==1) cout<<max1;
	else if(m==2) cout<<solve2(n);
	else if(m==n) cout<<solve3(n);
	else if(n<=31&&m!=1&&m!=2&&m!=n) cout<<solve1(n,m);
	return 0;
}
