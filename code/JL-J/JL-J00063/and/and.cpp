#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005],b[200005],n,m,ans;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(unsigned long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(unsigned long long i=1;i<=m;i++){
        b[i]=a[n-i+1];
    }
    ans=b[1];
    for(unsigned long long i=2;i<=m;i++){
        ans=ans&b[i];
    }
    cout<<ans;

return 0;
}
