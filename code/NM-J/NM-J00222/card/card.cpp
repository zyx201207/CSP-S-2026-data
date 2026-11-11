#include<bits/stdc++.h>
using namespace std;
long long zq[10000086],n,m,cnt[100000086];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>zq[i];
    }
    sort(zq+1,zq+n+1);
    for(int i=1;i<=n;i++){
        cnt[zq[i]]++;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[zq[i]]<<' ';
    }
    return 0;
}
