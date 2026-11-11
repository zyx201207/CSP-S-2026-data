#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200011;
int n,m;
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        int ans=0;
        // find 1-> first>2 -1
        for(int j=i;j<=n;j++){
            if(a[j]>a[i]){ans=j;break;}
        }
        if(i==m) ans++;
        cout<<ans-1<<" ";
    }
    return 0;
}
