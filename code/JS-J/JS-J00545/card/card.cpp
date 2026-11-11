#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],b[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]+b[i-1];
    }
    for(int i=1;i<m;i++)
        cout<<n-b[i]<<" ";
    cout<<n;
    return 0;
}
