#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[20005],b[20005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=n;i>=n-m+1;i--)
    {
        b[i]=a[i];
    }
    long long ans=b[n];
    for(int i=n-1;i>=n-m+1;i--)
    {
        ans=ans&b[i];
        //cout<<b[i]<<" ";
    }
    cout<<ans;
    return 0;
}
