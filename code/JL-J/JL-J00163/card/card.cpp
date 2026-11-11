#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b[500005]={0},maxn=i;
        bool vis[500005]={0};
        for(int j=i;j<=n;j++){
            if(vis[a[j]]) b[a[j]]=j;
            else vis[a[j]]=1;
        }
        for(int j=i;j<=n;j++){
            maxn=max(b[a[j]],maxn);
        }
        for(int j=maxn;j<=n;j++){
            c[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
