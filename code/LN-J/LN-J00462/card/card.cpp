#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],fl[300005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        fl[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<fl[i]<<' ';
    }
    return 0;
}
