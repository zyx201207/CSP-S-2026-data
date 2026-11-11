#include <bits/stdc++.h>
using namespace std;
long long b,d;
int n,a[200001];
char c[200001];
string e;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        b+=a[i];
        for (int j=1;j<=a[i];j++)
        {
            e+=c[i];
        }
    }
    for (int i=0;i<=b/2;i++)
    {
        if (e[i]!=e[b-i-1])
        {
            e[b-i-1]=e[i];
            d++;
        }
    }
    cout<<d;
    fclose();
    fclose();
    return 0;
}
