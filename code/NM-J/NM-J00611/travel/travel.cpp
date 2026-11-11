#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int e,f,g,h;
    if(a==c)
    {
        e=1;
        if(b[0]==d[0]&&b[1]==d[1])
        {
            f=1; 
        }
        else
        {
            f=0;
            g=0;
            h=0;
        }
    }
    else
    {
        e=0;
        f=0;
        g=0;
        h=0;
    }
    cout<<e<<f<<g<<h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
