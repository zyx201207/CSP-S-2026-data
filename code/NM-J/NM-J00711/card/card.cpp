#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],vis[300005];
int main{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    for(int k=1;k<=n;k++){
        if(b[k]==a[j]){
            b=0;
            b[j]=a[j];
        }
    else b[j]=a[j];

    }
    }
    for(int k=1;k<=n;k++){
        vis[b[k]]++;
        b=0;

    }

    }
    for(int i=1;i<=m;i++){
        cout<<vis[i];
    }

    return 0;
}
