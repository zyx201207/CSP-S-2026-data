#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+100;
long long a[N];

int main()
{

freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    long long n,m,maxa=0,daan=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    sort(a,a+n);
    for(int i=1;i<m;i++)
    {
        daan=a[n-i]&a[n-i-1];

    }
    cout<<daan;
    return 0;
}
