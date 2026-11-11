#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    sort(a+1,a+n+1);
    int ans=a[n];
    for(int j=n-1;j>=n-m+1;j--)
        ans&=a[j];
    cout<<ans<<endl;
    return 0;
}
