#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int v[200005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        int f[30005]={0},tot=1;
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                f[a[j]]=tot;
                v[tot++]=a[j];
            }else{
                for(int k=f[a[j]]+1;k<=tot;k++){
                    v[k]=0;
                }
                tot=f[a[j]]+1;
            }
        }
        for(int j=1;j<=tot;j++){
            ans[v[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
