#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cnt[a[i]]+=i;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
