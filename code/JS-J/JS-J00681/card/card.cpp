#include<bits/stdc++.h>
#define int long long

int N,M;
int arr[500005];

namespace baoli{
    bool in[500005];
    int ans[500005];
    std::map<int,int> mp;
    void solve(){
        for(int i=N;i>=1;i--){
            if(!mp[arr[i]]){
                mp[arr[i]] = i;
            }
        }
        for(int i=1;i<=N;i++){
            std::stack<int> st; memset(in,0,sizeof in);
            for(int j=i;j<=N;j++){
                if(mp[arr[j]] > j)j = mp[arr[j]];
                if(!in[arr[j]]){
                    st.push(arr[j]); in[arr[j]] = 1;
                }else{
                    while(st.top() != arr[j] && st.size()){
                        in[st.top()] = 0; st.pop();
                    }
                }
            }
            while(!st.empty()){
                ans[st.top()]++; st.pop();
            }
        }
        for(int i=1;i<=M;i++)printf("%lld ",ans[i]);
    }
}

signed main(){
    freopen("card.in","r",stdin); freopen("card.out","w",stdout);
    scanf("%lld %lld",&N,&M);
    for(int i=1;i<=N;i++)scanf("%lld",arr+i);
    baoli::solve();
    return 0;
}
