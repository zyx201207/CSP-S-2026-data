#include<bits/stdc++.h>
using namespace std;
int main()
 {
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	long long ejz=0,max1=0;
 	int n,m;
 	cin>>n>>m;
 	long long b=0;
 	long long a[n];
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 		while(a[i]!=0)
 		{
 			ejz=ejz*10+a[i]%2;
 			if(a[i]%2==0)
 			{
 				b++;
			 }
 			a[i]=a[i]/2;
		 }
		 for(int j=1;j<=b;j++)
		 {
		 	ejz=ejz*10;
		 }
		 a[i]=ejz;
		 ejz=0;
		 b=0;
		 max1=max(max1,a[i]);
	 }
	 if(m==1)
	 {
	 	cout<<max1;
	 }
	 
	 
 	return 0;	
 }
