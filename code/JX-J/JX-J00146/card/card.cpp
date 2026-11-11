#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],vis[N],ans[N],sum[N],k=0;
int main(){
    memset(vis,0,sizeof vis);
    memset(ans,0,sizeof ans);
    memset(sum,0,sizeof sum);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                ans[k++]=a[j];
                vis[a[j]]=1;
            }
            else{
                memset(ans,0,sizeof ans);
                memset(vis,0,sizeof vis);
                k=0;
                ans[k++]=a[j];
                vis[a[j]]=1;
            }
        }
        for(int j=1;j<=k;j++){
            sum[j]+=ans[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout << sum[i] << " ";
    }
    return 0;
}
