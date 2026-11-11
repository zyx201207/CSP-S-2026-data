#include <bits/stdc++.h>
using namespace std;

string jisuan(long long a,string b)
{
    string c;
    c=b;
    for (int i=0;i<a-1;i++)
    {
        b=b+c;
    }
    return b;
}



int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long a,n,e=0;
    string b,f,m;
    cin>>n;
    for (int j=1;j<=n;j++)
    {
        a=0;
        b="0";
        cin>>a>>b;
        f=f+jisuan(a,b);
    }

    for (int i=0;i<f.size();i++)
    {
        if (f[i]==f[f.size()-i-1])
        {
            e=e+0;
        }
        else
        {
            e=e+1;
        }
    }
    cout<<e/2;

    return 0;
}
