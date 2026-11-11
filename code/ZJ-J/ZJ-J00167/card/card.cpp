#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int& i:a) cin>>i,--i;
    vector<int> las(m,-1),rt(m,-1);
    vector<int> fa(n);
    for(int i=n-1;i>=0;--i) {
        if(~las[a[i]]) {
            fa[i]=las[a[i]];
        } else {
            fa[i]=i+1;
            rt[a[i]]=i;
        }
        las[a[i]]=i;
    }
    vector<int> dp(n,1);
    for(int i=0;i<n-1;++i) dp[fa[i]]+=dp[i];
    for(int i=0;i<m;++i) 
        cout<<(~rt[i]?dp[rt[i]]:0)<<" \n"[i==m-1];
}