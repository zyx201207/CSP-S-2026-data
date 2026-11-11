#include <bits/stdc++.h>
using namespace std;

bool vis[300005];
int cnt[300005];
int indexs[300005];
int arr[500005];
int que[300005];
int tail=1;

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[arr[j]]==false){
                que[tail++]=arr[j];
                indexs[arr[j]]=tail-1;
                vis[arr[j]]=true;
            }
            else{
                for(int k=indexs[arr[j]]+1;k<=n;k++){
                    vis[que[k]]=false;
                }
                tail=indexs[arr[j]]+1;
            }
        }
        for(int i=1;i<=m;i++){
            if(vis[i]){
                cnt[i]++;
            }
        }
        memset(indexs,0,sizeof(indexs));
        memset(que,0,sizeof(que));
        memset(vis,false,sizeof(vis));
        tail=1;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}