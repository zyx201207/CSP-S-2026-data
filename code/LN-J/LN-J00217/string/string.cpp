#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c=1;
    long long a[1000000];
    string b[10000500];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(b[1]!=b[i])
        {
            c=0;
        }
    }
    if(c==1)
    {
        cout<<0;
    }
    else
    {
        cout<<n/2*a[1];
    }
    else
    {

    }
    return 0;
}
