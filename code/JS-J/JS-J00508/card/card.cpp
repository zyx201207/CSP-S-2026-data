#include<bits/stdc++.h>
#define int long long
constexpr int N=2e5+5;
using namespace std;
int tree[N];
int n,m;
void add(int a,int b) {
    for (;a<=n;a+=(a&-a)) {
        tree[a]++;
    }
    b++;
    for (;b<=n;b+=(b&-b)) {
        tree[b]--;
    }
    return;
}
int query(int a) {
    int sum=0;
    for (;a;a-=(a&-a)) {
        sum+=tree[a];
    }
    return sum;
}
signed main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n+5);
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    vector<int> ans(m+5);
    for (int i=1;i<=n;i++) {
        for (int i=0;i<=n+5;i++) {
            tree[i]=0;
        }
        unordered_map<int,int> mp;
        for (int j=i;j<=n;j++) {
            if (mp.count(a[j]) and query(mp[a[j]])==0) {
                add(mp[a[j]],j-1);
            }
            mp[a[j]]=j;
        }
        for (const auto &it:mp) {
            if (query(it.second)==0) {
                ans[it.first]++;
            }
        }
    }
    for (int i=1;i<=m;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
