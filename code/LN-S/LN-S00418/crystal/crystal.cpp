#include <bits/stdc++.h>
using namespace std;
long long arr[100000];
int main ()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    bool pd=true;
    long long a;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        if(a!=arr[i]) pd=false;
    }
    if(pd) cout<<n;
    int maxjsq=0;
    sort (arr,arr+n);
    for(long long i=0;i<n;i++)
    {
        int jsq=0;
        long long x=m;
        for(long long j=i;j>=0;j--)
        {
            long long v=arr[i]-arr[j];
            if(v>x) break;
            x=x-v;
            jsq++;
            //cout<<arr[i]<<" "<<arr[j]<<endl;
        }
        if(maxjsq<jsq) maxjsq=jsq;
    }
    cout<<maxjsq;
    return 0;
}
