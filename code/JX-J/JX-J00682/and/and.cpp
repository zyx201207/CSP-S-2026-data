#include<bits/stdc++.h>
using namespace std;
long long n,m,d;
long long a[20005];
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(long long i=0;i<m-1;i++)
    {
        sort(a,a+n,cmp);
        //cout<<a[i]<<" "<<a[i+1]<<endl;
        a[i]&=a[i+1];
        d=a[i];
    }
    cout<<d;
    return 0;
}
