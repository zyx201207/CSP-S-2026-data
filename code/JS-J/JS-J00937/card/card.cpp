#include<bits/stdc++.h>
using namespace std;
int a[10003],ans[10003],b[10002];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    int a1,b1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]==1) a1=i;
        if(a[i]==2) b1=i;
    }
    for(int i=1;i<=n;++i){
        if(i<=a1) ans[1]++;
        if(i<=b1) ans[2]++;
    }
    for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
    return 0;
}
