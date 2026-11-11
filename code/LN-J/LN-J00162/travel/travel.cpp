#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s=1;
    string s1,s2,c1,c2;
    cin>>c1[1]>>s1[2]>>c2[1]>>s2[2];
    if(c1[0]==c2[0]&&c1[1]==c2[1])
       {
           cout<<'1';
           for(int i=0;i<2;i++)
           {
               if(s1[i]!=s2[i])
               {
                   cout<<'000';
                   s=0;
                   break;
               }
           }
           if(s==1)
            {
                cout<<'1';
                if(s1[2]<'D'&&s2[2]<'D'||s1[2]>'C'&&s2[2]>'C')
                {
                    cout<<'1';
                    if(s1[2]>'C'&&s2[2]>'C')
                        cout<<'1';
                    else if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')
                        cout<<'0';
                    else cout<<'1';
                }
                else cout<<'00';
            }
       }
       else cout<<'0000';

    return 0;
}
