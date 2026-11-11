#include <bits/stdc++.h>
using namespace std;
char s[1000000009],y;
int n,sum,r[1234],num=-10,e,f;
int main ()
{
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    cin >>n;
    int x=1;
    for (int i=1;i<=n;i++)
    {
        char b;
        int a;
        cin >>a>>b;
        for (int j=x;j<=a+x;j++)
            s[j]=b;
        x+=a;
        y=b;
    }
    int d=0;
    for (int i=1;i<=x;i++)
    {
        if (s[i]!=y)
        {
            d=1;
            break;
        }
    }
    if (d==0)
    {
        cout <<d;
        return 0;
    }
    for (int i=2;i<=x;i++)
    {
        if (s[i]==s[i-1])
            e++;
        else
            break;
    }
    for (int i=x;i>=2;i--)
    {
        if (s[i]==s[i+1])
            f++;
        else
            break;
    }
    if (e==f)
    {
        cout <<0;
        return 0;
    }
    if (d==1)
    {
        for (int i=1;i<=x;i++)
        {
            r[s[i]]++;
        }
        for (int i=1;i<=x;i++)
        {
            if (r[s[i]]>num)
                num=r[s[i]];
        }
        cout <<x-num;
    }
    return 0;
}
