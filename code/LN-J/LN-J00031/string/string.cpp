#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",std.in);
    freopen("string.out","w",std.out);
    string s;
    int n;
    long a,cnt=0;
    char b;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a>>b;
        for (int j=1;j<=a;i++)
        {
            s+=b;
        }
    }
    string h=reverse(s.begin,s.end);
    if (s.size()%2==0)
    {
        for (int i=0;i<=s.size/2-1;i++)
        {
            if (s[i]!=h[i])
                cnt++;
        }
    }
    else
    {
        for (int i=0;i<=s.size()/2-1;i++)
        {
            if (s[i]!=h[i])
                cnt++;
        }
    }
    cout <<cnt;
    return 0;
}
