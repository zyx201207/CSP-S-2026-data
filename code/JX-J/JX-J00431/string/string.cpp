#include <iostream>
using namespace std;
int a,b,f;
string c,d,e;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string,out","w",stdout);
    cin>>a;
    for (int i=1;i<=a;i++)
    {
        cin>>b>>c;
        for (int j=1;j<=b;j++)
        {
            d+=c;
        }
    }
    for (int i=0;i<d.length();i++)
    {
        e+=d[d.length()-1];
        if (e[i]!=d[i])
        {
            f++;
        }
    }
    cout<<f/2;
}
