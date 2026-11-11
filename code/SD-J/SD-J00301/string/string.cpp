#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n);
	vector<char> c(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=0,r=n-1;
	long long ans=0;
	long long L=a[l],R=a[r];
	while(l<r)
	{
		char cl=c[l];
		char cr=c[r];
		long long t=min(L,R);
		if(cl!=cr)
		{
			ans+=t;
		}
		L-=t;
		R-=t;
		if(L==0)
		{
			l++;
			L=a[l]; 
		}
		if(R==0)
		{
			r--;
			R=a[r]; 
		}
	}
	cout<<ans;
	return 0;
 } 
