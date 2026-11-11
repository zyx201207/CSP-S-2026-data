#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[105],ans=0,t=0;
    char b[1005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        ans+=a[i];
    }
    if(n==1)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]==b[i+1])
        {
            t=0;
        }
        else{
            t=1;
            continue;
        }
    }
    if(t==0)
    {
        cout<<"0";
        return 0;
    }
    else{
        cout<<ans/2;
        return 0;
    }
}
