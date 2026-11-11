#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    bool t;
    cin>>n>>m;
    long long a[n],i,b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
        if(i==0)
            b[0]=0;
        else
            b[i]=b[i-1]+i*(a[i]-a[i-1]);
    for(i=0;i<n;i++)
        if(b[i]>m)
    {
        t=true;
        cout<<i;
        break;
    }
    if(!t)
        cout<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
