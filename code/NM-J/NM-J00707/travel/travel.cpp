#include <bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r".stdin);
    freopen("travel.out","w".stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0; i<4; i++)
    {
        if(c1!=c2)
        {
            cout<<0;
        }
    }
    if(c1==c2&&s1+'1'==s2)
    {
        cout<<1111;
    }
    else if(a[0]==a[2]&&a[1]+'1'=='D')
    {
        cout<<1100;
    }
    return 0;

}

