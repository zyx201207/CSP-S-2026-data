#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],b[500005],c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]=i;
        b[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=c[a[i]];j<n;j){
            j++;
            b[a[j]]++;
            j=c[a[j]];
        }
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<' ';
    return 0;
}
