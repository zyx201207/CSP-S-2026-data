#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool l=1;
    vector<int> card(n+1),cnt(m+1,0);
    for(int i=1;i<=n;++i){
        cin>>card[i];
        if(i>=2&&card[i-1]>card[i]) l=0;
    }
    if(l){
        int tt=1;
        for(int i=1;i<=n;++i){
            if(card[i]>tt){
                cnt[tt]+=cnt[tt-1];
                tt++;
            }
            cnt[tt]++;
        }
        cnt[tt]+=cnt[tt-1];
        for(int i=1;i<=m;++i) cout<<cnt[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;++i){
        vector<int> sy;
        for(int j=i;j<=n;++j){
            for(int k=0;k<sy.size();++k){
                if(card[j]==sy[k]){
                    sy.erase(sy.begin()+k,sy.end());
                    break;
                }
            }
            sy.push_back(card[j]);
        }
        for(int ij=0;ij<sy.size();++ij){
            cnt[sy[ij]]++;
        }
    }
    for(int i=1;i<=m;++i) cout<<cnt[i]<<" ";
    return 0;
}
