#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],lstv[N],lst[N];
int ans[N],ed[N],vis[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) lstv[i]=n+1;
    memset(ed,0x3f,sizeof(ed));
    for (int i=1;i<=n;i++){
        lst[i]=lstv[a[i]];
        lstv[a[i]]=i;
    }
    set<int> s;
    for (int i=n;i>=1;i--){
        if (vis[a[i]]){
            s.insert(lst[i]);
            continue;
        }
        if (!s.empty()){
            auto it=s.lower_bound(i);
            if (it==s.begin()){
                if (vis[a[i]]){
                    s.insert(lst[i]);
                    continue;
                }
                if (ed[a[i]]>i) ans[a[i]]+=i,vis[a[i]]=1;
                ed[a[i]]=0;
            }
            else{
                if (ed[a[i]]<i){
                    s.insert(lst[i]);
                    continue;
                }
                --it;
                ans[a[i]]+=(i-(*it));
                ed[a[i]]=*it;
                //cerr<<"*it"<<(*it)<<' ';
                //cerr<<"i="<<i<<" "<<"a[i]="<<a[i]<<" "<<ans[a[i]]<<"\n";
            }
        }
        else{
            ans[a[i]]=i;
            ed[a[i]]=0;
        }
        s.insert(lst[i]);
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
