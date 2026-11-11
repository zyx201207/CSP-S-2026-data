#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[300005],c[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(ans,0,sizeof(ans));
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int tot=0;
        for(int j=i;j<=n;j++){
            if(b[a[j]]==0){
                b[a[j]]=++tot;
                c[tot]=a[j];
            }
            else{
                for(int k=b[a[j]]+1;k<=tot;k++){
                    b[c[k]]=0;
                    c[k]=0;
                }
                tot=b[a[j]];
            }
        }
        for(int j=1;j<=tot;j++){
            ans[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
