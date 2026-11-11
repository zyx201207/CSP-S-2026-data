
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string out","w",stdout);
    int n,m,p[1000000000];
    char o[100000000];
    string s;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> p[i] >> o[i];
    }
    for (int i=n;i<=n;i++)
    {
        for (int j=1;j<=p[i];j++)
        {
            s+=o[i];
        }
    }
    int num=0;
    for (int i=0;i<s.length()/2;i++)
    {
        if(s[i]!=s[s.length()-i-1])
        {
            num++;
        }
    }
    )cout <<num;
}
