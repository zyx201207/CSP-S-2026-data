#include<bits/stdc++.h>
using namespace std;
char a[5][18];
int main()
{
    string s1,s2;int c1,c2;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2)
    {
        for(int i=1; i<=5; i++)
        {
            for(int j=1; j<=18; j++)
            {
                if(('s1'+1=='s2'+1)){
                       cout<<"1111";
                break;
                }
                else {
                     cout<<"1110";
                     break;
                }
            }
        }

    }

    return 0;
}
