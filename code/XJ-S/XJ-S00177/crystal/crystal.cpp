#include<bits/stdc++.h>
using namespace std;
long long int n,m,l,r,sum,a[500005],ans; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	//for(i=1;i<=n;i++)
	  //cout<<a[i]<<' ';
	//cout<<endl;
	
	l=1;r=1;
	while(r<=n)
	{
		sum=0;
		//cout<<l<<' '<<r<<' ';
		for(i=l;i<=r;i++)
		{
			sum+=(a[r]-a[i]);
		}
		if(sum<=m)
		  ans=max(ans,r-l+1);
		
		if(sum>=m)
		  l++;
		else
		  r++;
		
		//if(sum<=m)
		  //ans=max(ans,r-l+1);
		cout<<sum<<endl;
	}
	cout<<ans;
	return 0;
} 
/*
输出的是对水晶加值后的数值相同的数量，且进行操作的水晶需和输出一样


6 20
7 -1 15 -5 20 20
3


-5 -1 7 15 20 20
*/
