#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    string s,c[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int o=1;o<=n;o++)
    {
        for(int j=1;j<=a[o];j++)
        {
            s=c[o];
        }
    }
    if(n<=1)
    {
        cout <<0;
    }
    return 0;
}
