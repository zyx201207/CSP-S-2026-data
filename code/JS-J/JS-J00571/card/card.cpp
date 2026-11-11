#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,a[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans[m+5ll]={};
    for(int i=1;i<=n;i++){
        int d[n+5ll]={},g[n+5ll]={};
        for(int j=i;j<=n;j++){
            if(g[a[j]]==0||d[g[a[j]]]==1){
                g[a[j]]=j;
            }else{
                fill(d+g[a[j]],d+j,1);
                g[a[j]]=j;
            }
        }
//        for(int j=i;j<=n;j++){
//            cout<<d[j]<<" ";
//        }
//        cout<<"\n";
        for(int j=i;j<=n;j++){
            if(d[j]==0){
                ans[a[j]]++;
            }
        }
    }
    for(int j=1;j<=m;j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}

