#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    deque<pair<int,char>> ac(n);
    for(auto& [a,c]:ac) cin>>a>>c;
    ll res=0;
    while(ac.size()>1) {
        auto& [a1,c1]=ac.front();
        auto& [a2,c2]=ac.back();
        
        int cnt=min(a1,a2);
        if(c1!=c2) res+=cnt;
        a1-=cnt;
        a2-=cnt;
        if(!a1) ac.pop_front();
        if(!a2) ac.pop_back();
    }
    cout<<res<<'\n';
};