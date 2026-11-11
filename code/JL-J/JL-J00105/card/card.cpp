#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
int n,m,a[N],vis[N],ans[N],cnt=0,num[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                cnt++;
                vis[a[j]]=cnt;
                ans[cnt]=a[j];
            }
            else{
                int tmp=vis[a[j]];
                for(int k=vis[a[j]];k<=cnt;k++){
                    vis[ans[k]]=0;
                }
                cnt=tmp-1;
                cnt++;
                vis[a[j]]=cnt;
                ans[cnt]=a[j];
            }
        }
        for(int j=1;j<=cnt;j++){
            num[ans[j]]++;
        }
        for(int j=1;j<=m;j++){
            vis[j]=0;
        }
        cnt=0;
    }
    for(int i=1;i<=m;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
