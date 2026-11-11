#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],res;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ax=0;
    for(int k=1;k<=n;k++){
    ax=a[k];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ax=max(ax,ax&a[i]);
        }
    }
    res=max(res,ax);
    }
    cout<<res;
    return 0;
}
