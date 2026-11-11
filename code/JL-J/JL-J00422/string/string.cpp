#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1000];
    char c[1000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        if((a[i]==a[i+1])||(c[i]==c[i+1]))
            cout<<0;
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        if((c[1]==c[2])||(a[1]==a[2]))
        {
            cout<<0;
            return 0;
        }
        else
        {
            if(a[1]>a[2]) cout<<a[2];
            if(a[1]<a[2]) cout<<a[1];
        }
    }
    return 0;
}

