#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >>n >>m;
    long long a[200005];
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n+1);
    int ans=a[n];
    for (int i=n,j=1;j<=m;i--,j++)
    {
        ans&=a[i];
    }
    cout << ans;
    return 0;
}
