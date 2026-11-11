#include<bits/stdc++.h>
using namespace std;
int n,l=0,r;
long long x;
int a[200000][2];
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n-1;
	for(int i=0;i<n;i++)
	{
		char c;
		cin>>a[i][0]>>c;
		a[i][1]=c;
	}
	while(l<=r)
	{
		int i=a[l][0]-a[r][0];
		if(a[l][1]!=a[r][1])
		{
			x+=min(a[l][0],a[r][0]);
		}
		if(i>0)
		{
			r--;
			a[l][0]=i;
		}else if(i<0)
		{
			l++;
			a[r][0]=i;
		}else
		{
			l++;
			r--;
		}
	}
	cout<<x;
	return 0;
}
