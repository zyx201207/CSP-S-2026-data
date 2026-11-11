#include<bits/stdc++.h>
using namespace std;
long long	c=0,s=0,a[200010],n,m=1;
char b[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    int l=1,r=n,ll=0,rr=0; 

	for(int i=1;i<=n;i++)
	{
		 cin>>a[i]>>b[i];
		 c+=a[i]; 
	 }
	while(m<=c-m) 
	{
		if(b[l]!=b[r])
		{
			s++;	
		 } 
		 ll++;
		 rr++;
		 if(ll>=a[l])
		 {
		 	ll=0;
		 	l++;
		 }
		if(rr>=a[r])
		 {
		 	rr=0;
		 	r--;
		 }
		m++;
	}
	cout<<s;
	return 0;
}
