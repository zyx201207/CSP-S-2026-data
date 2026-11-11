#include<bits/stdc++.h>
using namespace std;
long long a[511111];
int main()
{
    freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long e=m,j=n-1,ans=0;
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
        if(i!=n-1)
        {
            e+=(i-j+1)*(a[i+1]-a[i]);
        }
        while(e-(a[i]-a[j-1])>=0 && j>0)
        {
            j--; 
            e-=(a[i]-a[j]);
        }
        ans=max(ans,(i-j+1));
    }
    cout<<ans;
    return 0;
}