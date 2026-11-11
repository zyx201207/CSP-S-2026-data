#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[500005],b=0,ca[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b+=a[i];
    }
    b/=n;
    for(int i=0;i<n;i++)
    {
        if(b>a[i])
        {
            ca[i]=b-a[i];
        }
        else
        {
            ca[i]=a[i]-b;
        }
    }
    sort(ca,ca+n);
    long long cs=0;
    for(int i=0;i<n;i++)
    {
        cs+=ca[i];
        if(cs==m)
        {
            cout<<i+1;
            return 0;
        }
        else if(cs>m)
        {
            cs-=ca[i];
            cout<<i+1;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
