#include<bits/stdc++.h>
using namespace std;
long long n,a[200004],sum;
char c[200004];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n/2;i++)
    {
        if(c[i]!=c[n-i+1]) sum+=max(a[i],a[n-i+1]);
    }
    cout<<sum;
    return 0;
}
