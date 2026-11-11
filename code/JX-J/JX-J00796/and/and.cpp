#include<bits/stdc++.h>
using namespace std;
int a[200020];
int main()
{
    freopen("and.in" , "r" ,"std.in");
    freopen("and.out","w","std.out");
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    cout << a[m];
    return 0;
}
