#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200001];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+1+n);
    int t=a[n];
        for(int i=1;i<=m-1;i++)
        {
            t=t&a[n-1];
            n--;
        }
    cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
