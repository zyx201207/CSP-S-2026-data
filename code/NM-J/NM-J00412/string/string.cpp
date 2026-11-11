#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("stringin",r,stdin);
    //freopen("stringout",w,stdout);
    long long n,a[200000],sum=0;
    char x[200000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>x[i];
        sum+=a[i];
    }
    if(sum%n==0)
    {
        cout<<sum%n;
    }
    else
    {
        cout<<sum%n+1;
    }
    return 0;
}
