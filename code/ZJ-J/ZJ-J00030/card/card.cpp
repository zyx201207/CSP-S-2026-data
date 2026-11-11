#include<bits/stdc++.h>
using namespace std;
int a,b,c[500009],d[500009]={};
void s(int x,int y)
{
	if(x>y)return;
	for(int h=x;h<=a;h++)
	    if(c[h]==c[y])
	    {
	    	s(x,h-1);
	    	d[c[y]]++;
	        return;
		}
	return; 
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int h=1;h<=a;h++)cin>>c[h];
	for(int h=1;h<=b;h++)s(h,a);
	d[b]++;
	for(int h=1;h<=b;h++)cout<<d[h]<<" ";
	return 0;
}