#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,t,i,j,a[500005],b[300005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=n;i>=1;i--)
	{
		if(b[a[i]]==0)b[a[i]]=i+1;
	}
	for(t=1;t<=n;t++)
	{
		i=0;
		b[a[0]]=t;
		while(i<=n)
		{
			i=b[a[i]];
			c[a[i]]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
/*

4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

3121323121
      3  1
      
 121323121
         1
   
  21323121
        21
     
   1323121
         1
         
    323121
      3  1
      
     23121
        21
        
      3121
      3  1
      
       121
         1
         
        21
        21
        
         1
         1
         

*/