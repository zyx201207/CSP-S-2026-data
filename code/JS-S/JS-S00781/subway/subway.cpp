#include <bits/stdc++.h>
using namespace std;

const int M=500005;

int c,n,m,d,q;
int w[M];
vector<int> a[505],t[505];
vector<pair<int,int>> line[M];

int dfs(int l,int r){
    if(l==r){
        return 0;
    }

    int ret=INT_MAX;
    for(auto x:line[l]){
        for(auto y : a[x.first]){
            ret=min(ret,dfs(y,r)+t[x.first][x.second-1]);
        }
    }
    cout<<l<<endl;

    if(ret==INT_MAX) ret=0;
    return ret;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        int k;
        cin>>k;

        for(int j=1;j<=k;j++){
            int x,y;
            cin >> x >> y;

            a[i].push_back(x);
            t[i].push_back(y);
            line[x].push_back({i,j});
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        int ans=w[l]+w[r]+dfs(l,r);
        cout<<ans<<endl;
    }

    return 0;
}