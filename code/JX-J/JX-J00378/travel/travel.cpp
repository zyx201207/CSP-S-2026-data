#include<bits/stdc++.h>
using namespace std ;
int main () {
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,c2,s1,s2;
cin>>c1>>s1>>c2>>s2;
string a=s1.substr(0,1);
string b=s2.substr(0,1);
   string c3= s1.substr(2,2);
   string d3= s2.substr(2,2);
if(c1==c2&&c1!="01"&&c1!="16")
{
     cout << 1 ;

}
else{
    cout << 0 ;
}
if(a==b)
    {
        cout << 1;

    }
    else{
        cout << 0;
    }
    if(c3=="A"|| c3 == "B"|| c3=="C")
         {
             if(d3=="A"||d3=="B"||d3=="C")
             {
                 cout << 1;
             }

         }
         else{
            cout << 0;
         }
         if(c3=="D"||c3=="E")
         {
             if(d3=="D"||d3=="E")
             {
                 cout << 1 ;
             }
         }
       if(a==b||c3==d3)
       {
           cout << 1 ;

       }
       else{
        cout << 0;
       }
return 0 ;
}
