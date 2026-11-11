#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
string s1s,s2s,s1n,s2n;
string ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        ans[0]='1';
    }
    else{
        ans[0]=ans[1]=ans[2]=ans[3]='0';
        for(int i=0;i<4;i++)
        {

            cout<<ans[i];
        }
        return 0;
    }
    s1s=s1.substr(0,2);
    s2s=s2.substr(0,2);


    if(s1s==s2s)
    {

        ans[1]='1';
    }
    else {
        ans[1]=ans[2]=ans[3]='0';
    for(int i=0;i<4;i++)
        {

            cout<<ans[i];
        }
        return 0;
    }


   if((int(s1[2])<=67 && int(s2[2])<=67) || (int(s1[2])>=68 && int(s2[2])>=68))
   {

       ans[2]='1';
   }
   else ans[2]='0';
   if((int(s1[2])==66 && int(s2[2])==65 )||(int(s1[2])==65 && int(s2[2])==66 )|| (int(s1[2])==66 && int(s2[2])==67) || (int(s1[2])==67 && int(s2[2])==66) )
   {

       ans[3]='1';
   }
   else if((int(s1[2])==68 && int(s2[2])==70) || (int(s1[2])==70 && int(s2[2])==68))
   {

       ans[3]='1';
   }
    else ans[3]='0';
    for(int i=0;i<4;i++)
    {

        cout<<ans[i];
    }
    return 0;
}

