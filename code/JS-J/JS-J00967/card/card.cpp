#include<bits/stdc++.h>
using namespace std;
int g[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int s[500005];
    int a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int vis=0;
        for(int k=i;k<=n;k++){
            for(int j=1;j<=vis;j++){
                if(a[k]==s[j]){
                    vis=j-1;
                    break;
                }
            }
            vis++;
            s[vis]=a[k];
        }
        for(int j=1;j<=vis;j++){
            g[s[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<g[i]<<" ";
    }
}
