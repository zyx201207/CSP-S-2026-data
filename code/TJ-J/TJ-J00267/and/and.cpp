#include<bits/stdc++.h> 
using namespace std;
int main()
{freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
long long a[200005],max=1e9;
cin>>n>>m;
for(int i=1;i<=n;i++)
{    cin>>a[i];
}
for(int i=1;i<=n;i++)
{    for(int j=i+1;j<=n;j++)
     {    
		       if(a[i]|a[j]>max)      
			   {    max=a[i]|a[j]; 
			   }  
	 }
}
cout<<max;
return 0;
}
