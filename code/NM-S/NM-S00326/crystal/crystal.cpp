#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//5 8 -3 -1 2 2 7
	//5 5 1 2 4 8 9
	//9 4 5 6 3 9 2 9 12 26 1
	//15 10 20 26 24 27 36 45 15 32 27 28 30 17 23 20 19	
	int n,m;
	cin>>n>>m;
	int a[100000]; 
	int s[100000];
	int b[100000];
	int x=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		s[i]=a[i+1]-a[i];
	}
	for(int i=0;i<n;i++)
	{
		b[i]=s[i]+s[i+1]*2;
		int ans=3;
		if(i<n-2)
		{
			if(b[i]<m)
			{
				if(b[i]+s[i+2]*3<m || b[i]+s[i+2]*3==m)
				{
					ans+=1;
				}
			}
		}
		if(i<n-3)
		{
			if(b[i]<m)
			{
				if(b[i]+s[i+3]*4<m || b[i]+s[i+3]*4==m)
				{
					ans+=1;
				}
			}
		}
		x=max(ans,x);
	}
	cout<<x;
	return 0;
}
