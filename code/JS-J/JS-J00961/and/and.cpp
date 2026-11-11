#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
long long a[N];
long long maxi=0;
void f1()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=n;j++)maxi=max(maxi,a[i]&a[j]);
        cout << maxi << ' ';
    }
    cout << maxi;
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    if(m==2)f1();return 0;
    cout << 1;
    return 0;
}
