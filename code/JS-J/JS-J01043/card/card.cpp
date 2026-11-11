#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int desk[500010];
bool vis[300010]={0};
int cnt[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        desk[i]=0;
        memset(vis,false,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                desk[j]=a[j];
                vis[a[j]]=1;
            }else{
                for(int k=i;k<=n;k++){
                    if(desk[k]==a[j]){
                        for(int l=k;l<=n;l++){            //4 3
                            desk[l]=0;                    //1 2 1 3
                        }
                        desk[k]=a[j];
                    }
                }
                vis[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(vis[j]==1){
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",cnt[i]);
    }
    return 0;
}
