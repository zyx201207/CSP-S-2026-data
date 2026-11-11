#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5;
int n,m;
int a[maxn];
int ans[maxn],cnt[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cnt[a[j]]++;
            if(cnt[a[j]]>1){
                memset(cnt,0,sizeof(cnt));
                cnt[a[j]]++;
            }
        }
        for(int j=1;j<=m;j++)
            if(cnt[j]!=0) ans[j]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
