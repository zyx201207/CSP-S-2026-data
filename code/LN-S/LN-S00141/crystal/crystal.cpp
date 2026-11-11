#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],xm=1000000,ans;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) {
        a[i]=a[i-1]+(a[i]-a[i-1])*(i-1);
        if(a[i]>m&&a[i-1]<=m) {
            xm=i-1;
        }
    }
    long long i=1,j=xm;
    ans=xm;
    while(j<=n) {
        while(a[j]-a[i]<=m&&j<=n) {
            j++;
        }
        while(a[j]-a[i]>m&&j<=n) {
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
