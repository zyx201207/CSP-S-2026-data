#include<bits/stdc++.h>
using namespace std;
int a,s,d,f[10086],sum=INT_MIN;
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>a>>s;
for(int i=0;i<a;i++)
{
	cin>>f[i];
}
for(int i=0;i<a;i++)
{
	int ans=s;
	for(int j=i;j>=0;j--)
	{
		if(ans-(i-j)<0) break;
		ans-=(i-j);
		d++;
		
	}
	sum=max(sum,d);
	d=0;
}
cout<<sum;
 return 0;
}
