#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],cnt[N],ans[N],add[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>q;
    for(int i=1;i<=n;i++){
        vector<int>q;
        memset(cnt,0,sizeof(cnt));
        for(int w=i;w<=n;w++){
            q.emplace_back(a[w]);
            cnt[a[w]]++;
            if(cnt[a[w]]>=2){
                while(cnt[a[w]]&&q.size()){
                    cnt[q[q.size()-1]]--;
                    q.pop_back();
                };
                q.emplace_back(a[w]);
                cnt[a[w]]++;
            }
        }
        // cout<<i<<": ";
        for(auto val:q){
            //cout<<val<<' ';
            ans[val]++;
        }
        // cout<<endl;
    }
    // for(int i=1;i<=n;i--){
    //     q.insert(q.begin(),a[i]);
    //     cnt[a[i]]++;
    //     if(cnt[a[i]]>=2){
    //         while(cnt[a[i]]){
    //             cnt[*q.begin()]--;
    //             q.erase(q.begin());
    //         }
    //         q.insert(q.begin(),a[i]);
    //     }
    //     for(auto val:q)ans[val]++;
    // }
    // for(int i=1;i<=n;i++){
    //     cnt[a[i]]++;
    //     if(cnt[a[i]]>=2)continue;
    //     for(int j=i+1;j<=n;j++){
    //         if(a[i]==a[j]){
    //             for(int w=i+1;w<=j-1;w++){
    //                 add[w]++;
    //             }
    //             break;
    //         }
    //     }
    // }
    // memset(cnt,0,sizeof(cnt));
    // for(int i=n;i>=1;i--){
    //     cnt[a[i]]++;
    //     if(cnt[a[i]]>=2)continue;
    //     ans[a[i]]=i;
    // }
    // for(int i=1;i<=n;i++){
    //     ans[a[i]]-=add[i];
    // }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/