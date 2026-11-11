#include<bits/stdc++.h>
using namespace std;
int n,t,num,cnt;

long a[100001]
int main()
{
    freopen("and.in","r",std.in);
    freopen("and.out","w",std.out);
    cin >>n>>t;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    sort(a+1,a+n+1);

    cout <<max(a[n]&a[n-1]&a[n-2],a[n]&a[n-1]&a[n-3]);

    return 0;

}
