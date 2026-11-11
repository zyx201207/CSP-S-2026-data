#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++) cin>>x;
    for(int i=0;i<m;i++){
        cout<<n-i<<" ";
    }
    return 0;
}
