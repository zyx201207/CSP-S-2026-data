#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if (m==1)
    {
        cout<<a[n-1];
        return 0;
    }
    return 0;
}
