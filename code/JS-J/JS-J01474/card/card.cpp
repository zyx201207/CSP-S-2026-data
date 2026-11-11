#include<bits/stdc++.h>
using namespace std;
int cnt[5005];
int a[5005];
bool vis[5005];
int x1[5005];
int x2[5005];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){//game
        int t=1;
        for(int i=1;i<=n;i++){
            vis[i]=0;
            x1[i]=0;
            x2[a[i]]=0;
        }
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                x1[t]=a[j];
                x2[a[j]]=t;
                t++;
                vis[a[j]]=1;
            }
            else{
                int t2=x2[a[j]];
                for(int k=t2;k<=t;k++){
                    x2[x1[k]]=0;
                    vis[x1[k]]=0;
                    x1[k]=0;
                }
                t=(t2-1);
                x1[t]=a[j];
                x2[a[j]]=t;
                t++;
                vis[a[j]]=1;
            }
        }
        /*for(int i=1;i<=n;i++){
            if(vis[a[i]]==1){
                cout<<1<<' ';
            }
            else{
                cout<<0<<' ';
            }
        }*/
        //cout<<endl;
        for(int i=1;i<=m;i++){
            if(vis[i]){
                cnt[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
}
