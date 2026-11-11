#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],nxt[300005],num[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        nxt[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int x=i;
        while(x<=n){
            x=nxt[a[x]];
            num[a[x]]++;
            x++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
