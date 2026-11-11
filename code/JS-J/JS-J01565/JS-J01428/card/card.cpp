#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],desk[300005];
vector<int> last[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int t=0;
        memset(last,0,sizeof(last));
        for(int j=i;j<=n;j++){
            last[a[j]].erase(upper_bound(last[a[j]].begin(),last[a[j]].end(),t),last[a[j]].end());
            if(!last[a[j]].empty()) t=last[a[j]].back()-1;
            desk[++t]=a[j];
            last[a[j]].push_back(t);
        }
        for(int j=1;j<=t;j++) ans[desk[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
