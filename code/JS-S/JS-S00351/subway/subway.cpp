#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
struct node{
    int x,t;
}a[N][M];
long long c,n,m,d,q,w[M],k[N],len,mn,cnt;
vector <pair<int,int> > T[N];
int solve(int st,int ed){
    for(int i=1;i<=n;i++){
        bool f=0;
        for(int j=1;j<=k[i];j++){
            if(a[i][j].x==st) f=1;
        }
        if(f){
            solve(a[i][1].x,a[i][1].t+w[st]);
            mn=min(mn,cnt);
            solve(a[i][2].x,a[i][2].t+w[st]);
            mn=min(cnt,mn);
        }
    }
    return mn;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>a[i][j].x>>a[i][j].t;
    }
    while(q--){
        int xr,yr;
        cin>>xr>>yr;
        len=0,mn=1e9;
        cout<<solve(xr,yr)+w[xr]+w[yr]<<'\n';
    }
    return 0;
}
