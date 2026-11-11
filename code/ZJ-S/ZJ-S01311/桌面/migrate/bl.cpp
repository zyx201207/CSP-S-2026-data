#include<bits/stdc++.h>
using namespace std;
int n,f[10005],g[10005],ans;
long long a[10005],d;
void ATRI() {
    cin>>n>>d;
    ans=0;
    for(int i=1; i<=n; i++) cin>>a[i];
    // for(int i=1; i<=n; i++) {
    //     for(int j=i+1; j<=n; j++) {
    //         if(a[j]-a[i]<=d) {
    //             printf("%d -> %d\n",i,j);
    //         }
    //     }
    // }
    for(int i=1; i<=n; i++) {
        f[i]=0, g[i]=1;
        for(int j=i+1; j<=n; j++) {
            f[j]=1e9;
            for(int k=i; k<j; k++) {
                if(a[j]-a[k]<=d) {
                    if(f[k]+1<f[j]) f[j]=f[k]+1, g[j]=g[k];
                    else if(f[k]+1==f[j]) g[j]+=g[k];
                }
            }
            if(g[j]==2) {
                ans++;
                // cout<<i<<' '<<j<<' '<<f[j]<<'\n';
                // if(f[j]>=3) exit(1);
            }
            // cout<<g[j]<<' ';
        }
        // cout<<'\n';
    }
    cout<<ans<<'\n';
}
int main() {
    int c,T;
    cin>>c>>T;
    while(T--) ATRI();
}