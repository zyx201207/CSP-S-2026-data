#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
int a,b;
string c,d;
string e="0000";
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a==b)
    {
        e[0]='1';
        int pa=(c[0]-'0')*10+c[1]-'0';
        int pb=(d[0]-'0')*10+d[1]-'0';
        if(pa==pb)
        {
            e[1]='1';
            if(c[2]>='D'&&d[2]>='D')
            {
                e[2]='1';
                e[3]='1';
            }
            else if(c[2]<'D'&&d[2]<'D')
            {
                e[2]='1';
                if(abs(c[2]-d[2])==1)
                    e[3]='1';
            }

        }

    }
    cout<<e;
    return 0;
}
