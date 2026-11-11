#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,c2,f1=0,f2=0;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
   	cout<<0000;
   	return 0;
    }
    else
    { 
        cout<<1;
        int ts1=s1[0]*10+s1[1],ts2=s2[0]*10+s2[1];
        if(ts1!=ts2)
        {
	  cout<<000;
        }
	else
	{
	   cout<<1;
	   if(s1[2]-'A'<=2) f1=1;
	   if(s2[2]-'A'<=2) f2=1;
	   if(f1==f2) 
	   {
	   	cout<<1;
	   	if(abs(s1[2]-s2[2])<=1) cout<<1;
	   	else cout<<0;
	   }
	   else cout<<00;
	   
	}
    }
} 
