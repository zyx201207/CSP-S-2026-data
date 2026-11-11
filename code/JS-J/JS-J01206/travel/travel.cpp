#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   string str1,str2,str3,str4;
   cin>>str1>>str2>>str3>>str4;
   if(str1==str3)
   {
   cout<<1;
   if(str2[0]==str4[0]&&str2[1]==str4[1])
   {
       cout<<1;
       if((str2[2]>='A'&&str2[2]<='C'&&str4[2]>='A'&&str4[2]<='C')||(str2[2]>='D'&&str2[2]<='F'&&str4[2]>='D'&&str4[2]<='F') )
       {
           cout<<1;
           if(str2[2]+1==str4[2]||str4[2]+1==str2[2])
            cout<<1;
           else cout<<0;
       }
       else cout<<"00";
   }
   else cout<<"000";
   }
   else cout<<"0000";


}
