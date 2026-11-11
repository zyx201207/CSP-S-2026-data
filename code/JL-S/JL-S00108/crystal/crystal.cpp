#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[500005];
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long ans=0;
    for(long long i=1;i<=n;i++){
        int cz=0;
        for(long long j=1;j<=i;j++)
            cz+=a[i]-a[j];
        if(cz<=m)
            ans++;
    }
    cout<<ans;
}
