#include<bits/stdc++.h>
using namespace std;
long long a[100000000010];
long long b[100000000001];
long long max(long long a,long long b)
{
	if(a<b)
	{
		return b;
	}
	else if(b<a){
	
		return a;
	}
}
int main()
{
	long long m,s,k=1;
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i-1]=a[i+1]-a[i];
	}
	long long cnt=1;
	for(int i=0;i<n;i++)
	{
		int cnt =1;
		int q=m;
		for(int j=i;j<n;j++)
		{
			s=b[i]*cnt;
			q=q-s;
			if(q<0)
			{
				k=max(k,cnt);
				break;
			}
			cnt++;
		}
	}		
	cout<<k;
}