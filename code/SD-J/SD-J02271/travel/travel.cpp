#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string rc,rs,xc,xs;
int r,x,cr,cx;
bool a[4];
a[0]=0;a[1]=0;a[2]=0;a[3]=0;
cin>>rc>>rs>>xc>>xs;
if(rc==xc)
{
	a[0]=1;
	
   if(rs==xs)
   {
	   a[1]=1;
   }
   if(x<=67 and r<=67)
   {
	   a[2]=1;
   }  
   else if(x>=68 and r>=68)
   {
	   a[2]=1;
   }
   if(x-r==1 or x-r==-1 and x==67 or x!=68 and r!=67 or r!=68)
   {
	   a[3]=1;
   }
}
cout<<a[0]<<a[1]<<a[2]<<a[3];
return 0;
}
