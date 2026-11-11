/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    bool f;
    int i;
};

int n,m,now=1;
vector<int> a;
unordered_map<int,Node> mp;
unordered_map<int,int> ans;

signed main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>n>>m;
    a.resize(n+1);
    for (int i=0;i<n;i++)
        cin>>a[i];
    if (n<=500) {
        for (int i=0;i<n;i++) {
        mp.clear();
        for (int j=i;j<n;j++) {
            if (mp[a[j]].f) {
                for (int i=1;i<=m;i++)
                    if (mp[i].i>mp[a[j]].i) {
                        mp[i].f=false;
                        mp[i].i=-1;
                    }
                now=mp[a[j]].i+1;
            }
            else {
                mp[a[j]].f=true;
                mp[a[j]].i=now++;
            }
        }
        for (int j=1;j<=m;j++)
            if (mp[j].f)
                ans[j]++;
    }
    for (int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    }
    else {
        for (int i=0;i<n;i++)
            cout<<0<<' ';
    }
    return 0;
}