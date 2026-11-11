#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("andin",r,stdin);
    //freopen("andout",w,stdout);
    char n,m,a[200000];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<a[n]&a[n-1];
    return 0;
}
