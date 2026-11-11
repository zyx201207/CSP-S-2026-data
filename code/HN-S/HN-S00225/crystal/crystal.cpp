#include<bits/stdc++.h>
using namespace std;

const int M=5e5+10;
int a[M];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	a[0]=a[1];
	long long he=0,ans=0;
	for(long long r=1,l=0;r<=n;r++)
	{
		he+=(a[r]-a[r-1])*(r-1);
		if(he>m)
		{
			while(he>m)
			{
				l++;
				he-=a[r]-a[l];
			}
		}
		
		ans=max(r-l,ans);
	}
	
	cout<< ans <<endl;
	return 0;	
} 
