#include<bits/stdc++.h>
using namespace std;
int a[500005],s[300005];
int d[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[a[i]]=i;
    }for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            d[a[j]]++;
            j=s[a[j]];
        }
    }for(int i=1;i<=m;i++) cout<<d[i]<<" ";
    return 0;
}
