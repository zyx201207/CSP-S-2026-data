#include<bits/stdc++.h>
using namespace std;
const int N=1E5*2+100;
int a[N];
int main()
{
    freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
    int n,t=0,ans=0,zonga=0,zongc=0;
    char c[N];
    cin>>n;
    a[n]=a[n-1];

    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        zonga+=a[i];
        zongc+=c[i];
        if(a[i]==a[i+1])
        {
            t++;
        }

    }
    if(n==1)
    {

        cout<<0;
        return 0;
    }
    if(t==n)
    {
        cout<<zongc;
        return 0;
    }

    if(n==2&&t!=n)
    {
        if(a[0]>a[1])
        {
            cout<<a[1];
            return 0;
        }
        if(a[1]>a[0])
        {
            cout<<a[0];
            return 0;
        }

    }

    for(int i=0;i<n;i++)
    {
        if(c[i]==c[i+1])
        {
            ans+=a[i]+a[i+1];
            zonga-=ans;
        }
        ans=0;
    }
    cout<<zonga;
}
