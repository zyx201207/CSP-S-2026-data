#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==a[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
