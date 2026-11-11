#include <bits/stdc++.h>
using namespace std;
int pre[3005],ans[3005];
bool f[5005];
int cards[5005],id[5005];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>cards[i];
        if(cards[i]<cards[i-1]) flag=0;
    }
    if(flag){
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int k=i;k<=n;k++)
            pre[cards[k]]=-1;
        for(int j=i;j<=n;j++){
            if(pre[cards[j]]==-1){
                f[j]=1;
                pre[cards[j]]=j;
                id[j]=cards[j];
            }else{
                int st=pre[cards[j]];
                for(int k=st;k<j;k++){
                    f[k]=0;
                    pre[cards[k]]=-1;
                }
                pre[cards[j]]=j;
                f[j]=1;
                id[j]=cards[j];
            }
        }
        for(int p=i;p<=n;p++){
            if(f[p])
                ans[id[p]]++;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
