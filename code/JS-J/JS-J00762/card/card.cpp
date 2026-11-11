#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll vis[500005];
ll died[500005];
ll cnt[500005];
int main(){
//si4 hu1 zai4 na3 li3 jian4 dao4 guo4
//dan4 shi4 wang4 le3.
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
//baoli 1~6
//maybe can get 7~12
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)vis[j]=-1,died[j]=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]!=-1){
                for(int k=vis[a[j]]+1;k<j;k++){
                    if(died[k]==0){
                        died[k]=j;
                        vis[a[k]]=-1;
                    }
                    else k=died[k];
                }
            }
            vis[a[j]]=j;
        }
        for(int j=1;j<=m;j++){
            if(vis[j]!=-1){
                cnt[j]++;
            }
            //cout<<vis[j]<<' ';
        }//cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
