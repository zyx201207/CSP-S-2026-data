#include <bits/stdc++.h>
using namespace std;

long long n,m,a[100000000];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long p=a[1];
    for(int i=1;i<=m;i++){
        p=p & a[i+1];
    }
    cout<<p;
    return 0;
}
