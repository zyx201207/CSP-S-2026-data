#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[500005],lst[500005];
bool vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    bool isA=true;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]<a[i-1])isA=false;
    }
    if(isA){
        for(int i=1;i<=n;i++){
            ans[a[i]]=max(ans[a[i]],i);
        }
        for(int i=1;i<=m;i++){
            cout << ans[i]<<" ";
        }
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)vis[j]=false;
            for(int j=1;j<=n;j++)b[j]=a[j];
            int ind =i;
            for(int j=i;j<=n;j++){
                if(lst[a[j]]<ind||!vis[a[j]]){vis[a[j]]=true;lst[a[j]]=j;}
                else{
                    ind=j;
                    lst[a[j]]=j;
                    for(int k=j-1;k>=lst[a[j]];k--)b[k]=-1;
                }
            }
            for(int j=ind;j<=n;j++)if(b[j]!=-1)ans[a[j]]++;
        }
        for(int i=1;i<=m;i++){
            cout << ans[i] << " ";
        }
    }
    return 0;
}
