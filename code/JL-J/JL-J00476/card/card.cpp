#include<bits/stdc++.h>
using namespace std;
int a[500001],ec[300001],ecid=0,ml[300001],ans[300001],vis[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(ml,-1,sizeof(ml));
    memset(ans,0,sizeof(ans));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
        ec[ecid]=a[i];
        vis[a[i]]++;
        ecid++;
        if(ml[a[i]]<0){
            ml[a[i]]=i;
        }
        else{
            int j=0;
            for(int k=0;k<ecid;k++){
                if(ml[ec[k]]<ml[a[i]]){
                    j++;
                    ml[ec[k]]=-1;
                    vis[ec[k]]--;
                }
                ec[k]=ec[k+j];
            }
            ecid-=j;
        }
        for(int j=0;j<ecid;j++){
            ans[ec[j]]++;
        }
    }
    for(int i=0;i<m;i++){
        if(vis[i]>1){
            ans[i]=ans[i]-vis[i]+1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
