#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt_ans[300005],cnt2[300005];
vector<int>cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        cnt[a[i]].push_back(i);
        ++cnt2[a[i]];
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(cnt2[a[j]]>=2){
                int tps=cnt[a[j]].size()-1;
                if(cnt[a[j]][tps]>j)j=cnt[a[j]][tps];
                cnt_ans[a[j]]++;
                continue;
            }
            cnt_ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;++i){
        cout<<cnt_ans[i]<<" ";
    }
}
