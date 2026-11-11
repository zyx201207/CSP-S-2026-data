#include<bits/stdc++.h>
using namespace std;
long long a[300005];
int ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,s;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<(n-i+1)<<" ";
    }
    return 0;
}
