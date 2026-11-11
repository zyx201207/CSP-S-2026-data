#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string b,c;
    long long n,a,s=0,d;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for (int j=1;j<=a;j++)
        {
            c+=b;
        }
    }
    for (int i=0;i<c.size()/2;i++)
    {
        if (c[i]-'0'==c[c.size()-1-i]-'0')
        {
            d++;
        }
        else
        {
            s++;
        }
    }
    cout<<s;
    return 0;
}
