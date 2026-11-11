#include <bits/stdc++.h>
using namespace std;
int n,m,a[5005],ans[3005];
void process(int a[],int round){
    if(round==n+1) return;
    int pos[5005]={},cur=1;
    bool appear[3005]={};
    memset(pos,-1,sizeof pos);
    for(int i=round;i<=n;i++){
        if(appear[a[i]]==0){
            appear[a[i]]=1;
            pos[a[i]]=cur;
            cur++;
        }
        else if(appear[a[i]]==1){
            int t=pos[a[i]];
            for(int k=pos[a[i]]+1;k<cur;k++){
                appear[a[k]]=0;
                pos[a[k]]=-1;
            }
            cur=pos[a[i]]+1;
        }
    }
    for(int k=1;k<=m;k++){
        if(appear[k]&&pos[k]!=-1) ans[k]++;
    }
    process(a,round+1);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    process(a,1);
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}