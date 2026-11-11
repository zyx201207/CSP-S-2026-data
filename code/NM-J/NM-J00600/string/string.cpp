#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a[100005],b[100005],n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n;i++)
    {
        if(n==1)
            ans=0;
        else
            continue;
        if(n==2&&b[1]==b[2])
            ans=0;
        else
            continue;
        if(n==2&&b[1]!=b[2])
            ans=1;
        else
            continue;

    }
    cout<<ans;
    return 0;
}
