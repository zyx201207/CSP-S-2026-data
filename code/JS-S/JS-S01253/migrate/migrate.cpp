#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,t,n,d,ans = 0;
vector<int> x;
vector<vector<pair<int,int> > > st;

void dfs(int xs,int cc){
    if (xs >= n)    return;
    auto it = upper_bound(x.begin(),x.end(),x[xs]+d);
    it--;int ed = it - x.begin();
    for (int j = xs+1;j <= ed;j++){
        if (st[xs][j].first == -1){
            st[xs][j].first = cc;
            st[xs][j].second = 1;
        }
        else if (st[xs][j].first == cc){
            st[xs][j].second++;
            if (st[xs][j].second == 2)   ans++;
            else if (st[xs][j].second == 3)  ans--;
        }
        else if (st[xs][j].first > cc){
            st[xs][j].first = cc;
            st[xs][j].second == 0;
        }
        dfs(j,cc+1);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--){
        ans = 0;
        cin>>n>>d;
        x.clear();x.resize(n);st.resize(n,vector<pair<int,int> >(n,{-1,0}));
        for (int i = 0;i < n;i++)   cin>>x[i];
        dfs(0,1);
        cout<<ans<<"\n";
    }
}
