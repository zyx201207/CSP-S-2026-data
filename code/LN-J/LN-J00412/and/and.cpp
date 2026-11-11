#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[200005],b[200005],maxx;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> m >>n;
    a[0]=0;
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
        a[i]=max(b[i],b[i]&a[i-1]);
        maxx=max(maxx,a[i]);
    }
    cout << a[n];
    return 0;
}
