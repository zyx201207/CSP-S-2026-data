#include<bits/stdc++.h>
using namespace std;
int main()
{
	 //freopen("card.in","r",stdin);
  //freopen("card.out","w",stdout);
	int m,n,a[56],g,f,t,y,c[67],d[67];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
      cin>>a[i];	
	}
   for(int i=1;i<=n;i++)
   {
     for(int y=i;y<=n;y++)
     {
	   if(a[y]!=a[y+1])
	   {
	     d[a[i]]++;
	   }
	   else
	   {
	   for(int r=i;r<=y-1;r++)
	   {
	   	a[r]=0;
	   }
	   }
	   
	 }
	 
   }
   for(int i=1;i<=m;i++)
   {
   	if(d[i]!=0)
   	{
   		cout<<d[i]<<endl;
	   }
   }
}
