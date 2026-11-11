#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin)
    freopen("string.out","w",stdout)
    string s;
    int n;
    string a,b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s[a[i-1]+j]=b[i];
        }
    }
}
