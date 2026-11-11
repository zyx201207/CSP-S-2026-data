#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]){
            cout<<i-1<<" ";
        }
    }
    cout<<n;
    return 0;
}
