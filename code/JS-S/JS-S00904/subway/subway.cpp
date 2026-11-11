#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
const int N=500006;
int c,m,n,d,q;
int w[N];
int a[505][1006];
int t[505][1006];
vector<pair<int,int> > g[505];
int solve(int x,int y,int r,int sum){
    if(a[x][3-y]==r){
        return sum+w[r]+t[x][3-y];
    }
    sum+=t[x][3-y];
    int ans=0x3f3f3f3f3f;
    for(pair<int,int> p:g[a[x][3-y]]){
        if(p.first==x) continue;
        ans=min(solve(p.first,p.second,r,sum+t[p.first][p.second]),ans);
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++){
            cin>>a[i][j]>>t[i][j];
            g[a[i][j]].push_back(mp(i,j));
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        int ans=0x3f3f3f3f3f;
        for(pair<int,int> l:g[x]){
            ans=min(solve(l.first,l.second,y,w[x]+t[l.first][l.second]),ans);//start l.first subway, l.second station, target is y
        }
        cout<<ans<<endl;
    }
    return 0;
}
