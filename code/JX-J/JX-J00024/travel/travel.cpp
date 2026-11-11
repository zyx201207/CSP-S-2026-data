#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int b1,b2,a1[30],a2[30];
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   cin>>c1>>s1>>c2>>s2;
   for(int i=0;i<2;i++)
   {
       a1[i]=s1[i];
       a2[i]=s2[i];
   }
   for(int j=2;j<=2;j++)
   {
	   b1=s1[j];
	   b2=s2[j];
   }
   if(c1==c2)
   {
	   cout<<"1";
      if(a1[1]==a2[1]&&a1[2]==a2[2])
      {
	      cout<<"1";
          if(((b1>=65&&b1<=67)&&(b2>=65&&b2<=67))||((b1>=68&&b1<=70)&&(b2>=68&&b2<=70)))
          {
               cout<<"1";
               if(b1+1==b2||b1-1==b2||(b1==68&&b2==70)||(b1==68&&b2==70)) cout<<"1";
               else cout<<"0";
           }
           else cout<<"00";
       }
       else cout<<"000";
    }
   else cout<<"0000";
    
   return 0;
}
