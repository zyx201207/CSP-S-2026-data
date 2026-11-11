#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int cnt[500005];
int cnt2[500005];
queue<int> ve;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cnt[a[j]]++;
            ve.push(a[j]);
            if(cnt[a[j]]>1){
                ve.pop();
                cnt[a[j]]--;
                while(ve.front()!=a[j]) cnt[ve.front()]--,ve.pop();
            }
        }
        while(1){
            if(ve.empty()) break;
            int u=ve.front();
            cnt2[u]++;
            ve.pop();
        }
        fill(cnt+1,cnt+500005,0);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt2[i]<<' ';
    }
    return 0;
}
