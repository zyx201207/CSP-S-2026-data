#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],ans=0;
	char b[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	 } 
	 int l=1,r=n,o,p,k;
	 while(l<r)
	 {
	 	o=max(a[l],a[r]);
	 	p=min(a[r],a[l]);
	 	k=o-p;
	 	if(b[l]!=b[r])
	 	ans+=p;
	 	if(a[l]>a[r])
	 	{
	 	a[l]=k;
	 	r--;
	 	continue;
	 }
	 	else if(a[l]<a[r])
	 	{
	 	a[r]=k;
	 	l++;
	 	continue;
	 }
	 else if(a[l]==a[r])
	 {
	 	l++;
	 	r--;
	 	continue;
	 }
	 }
	 cout<<ans;
	return 0;
 } 
