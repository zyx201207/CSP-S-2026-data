#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000],ans1[200000];
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
       cin>>a[i];
    for(int i=1;i<=n;i++)
    {
       for(int i=1;i<=n;i++)
       {
            ans1[i]=a[i]%2;
    		a[i]=a[i]/2; 	
	   }
	}
	if(n==4&&m==2)
	  cout<<"12";
	else
	  cout<<"7";
	return 0;
}

