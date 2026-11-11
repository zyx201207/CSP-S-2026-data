#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[500005],t[300005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
        t[i+1]+=t[i];
    }
    return 0;
}
