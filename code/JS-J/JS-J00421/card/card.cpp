#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 25,M = 3e5 + 15;
int n,m,a[N];
int ans[M];
struct node{
    int tme,num;
    bool operator < (const node A) const {
        if(num != A.num) return num < A.num;
        return tme < A.tme;
    }
};
set<node> suf;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0);    cout.tie(0);

    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];

    for(int i = n;i > 0;i--){
        auto tmp = suf.lower_bound(node{a[i],0});
        if(tmp == suf.end() || tmp -> num != a[i]) suf.insert(node{i,a[i]});
        else{
            for(auto it = suf.begin();it != suf.end();it++)
                if(it -> tme < tmp -> tme){
                    ans[it -> num] = max(ans[it -> num],it -> tme - i);
                    suf.erase(it);
                }
            suf.insert({i,a[i]});
        }
    }
    for(auto i : suf)
        ans[i.num] = max(ans[i.num],i.tme);

    for(int i = 1;i <= m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
