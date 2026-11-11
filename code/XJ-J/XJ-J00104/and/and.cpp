#include<bits/stdc++.h>
using namespace std;
long long int ans1,ans2,ans3,ans,a[666666],b,j,n,m,mans;
int fff(long long c,long long d)
{
	int i;
	long long s1[222]={0},s2[222]={0},x;
	ans=0;
	for(i=19;i>=0;i--)
	{
		x=pow(2,i);
		if(c>=x)
		c-=x,
		s1[i]=1;
	} 
	for(i=19;i>=0;i--)
	{
		x=pow(2,i);
		if(d>=x)
		d-=x,
		s2[i]=1;
	} 
	
	for(i=19;i>=0;i--)
	{
		if(s1[i]&&s2[i])
		ans+=pow(2,i);
	} 
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
cin>>n>>m;
int i;
for(i=1;i<=n;i++)
cin>>a[i],mans=max(mans,a[i]);
if(m==1){
cout<<mans;return 0;}
if(m==2)
{
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	{
		ans2=fff(a[i],a[j]);
		ans1=max(ans1,ans2);
	}
	cout<<ans1;
	return 0;
}
if(1)
{
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
}
return 0;
}
