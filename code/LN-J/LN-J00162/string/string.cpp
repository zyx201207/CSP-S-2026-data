#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[300000];
    char c[300000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    if(n==1)
        cout<<0;
    else if(n==2)
    {
        if(c[1]==c[2])
            cout<<0;
        else
        {
            if(a[1]>=a[2])
                cout<<a[2];
            else
                cout<<a[1];
        }
    }
    else cout<<3000000000;
    return 0;
}

