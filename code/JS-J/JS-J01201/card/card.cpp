#include<bits/stdc++.h>
using namespace std;
//24 pts
int vis[500003],a[500003],ans[500003],n,m;
bool st[500003];
int main(){
    //add
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);


    //delete

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=m;i++){
            vis[i]=-1;
        }
        for(int i=1;i<=n;i++){
            st[i]=false;
        }
        int r=j;
        for(;r<=n;r++){
            if(vis[a[r]]!=-1&&!st[vis[a[r]]]){
                for(int k=vis[a[r]];k<r;k++){
                    st[k]=true;
                }
            }
            vis[a[r]]=r;
        }
        for(int i=j;i<=n;i++){
            if(st[i])continue;
            ans[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
