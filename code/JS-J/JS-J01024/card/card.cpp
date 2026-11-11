#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
long long a[N],ans[N],cnt[N];
bool vis[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[a[i]]++;
    }
    if(n<=500&&m<=200){
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            for(int j=1;j<i;j++)vis[j]=1;
            ans[a[i-1]]--;
            for(int j=i;j<=n;j++){
                for(int k=i;k<j;k++){
                    if(a[k]==a[j]&&vis[k]==0){
                        for(int l=k;l<j;l++){
                            vis[l]=1;
                            ans[a[l]]--;
                        }
                    }
                }
            }
            cout<<i<<":\n";
            for(int j=1;j<=m;j++){
                cout<<j<<" "<<ans[j]<<endl;
                if(ans[j]>0)cnt[j]++;
            }
        }
        for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    }
    return 0;
}
