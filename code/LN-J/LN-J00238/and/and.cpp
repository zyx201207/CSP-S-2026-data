#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    long long ans=a[1];
    for(int i=2;i<=m;i++) {
        ans=ans&a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
