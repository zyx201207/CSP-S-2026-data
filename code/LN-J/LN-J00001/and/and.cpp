#include <bits/stdc++.h>
using namespace std;
long long a[299999];
long long b[299999];
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    bool Bflag=1,Aflag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=-1;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        }
        cout<<ans;
        return 0;
    }
    cout<<pow(2,n-m)-1;
    return 0;
}
