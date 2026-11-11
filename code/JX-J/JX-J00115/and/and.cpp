
#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>n>>m;
    long long * a=new long long[n+64];
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    long long max__=0;
    for(long long i=1;i<=n-m;i++)
    {
        long long t=0;
        for(long long j=i;j<=i+m;j++)
        {
            t=a[j]&a[j+1];
        }
        max__=max(max__,t);
    }
    cout<<max__<<endl;
    delete[] a;
    a=NULL;
    return 0;
}
