#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[m+1],ans[m+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
    }
    for(int i=1;i<m;i++){
        cout<<ans[i]<<' ';
    }
    cout<<n;
    return 0;
}
