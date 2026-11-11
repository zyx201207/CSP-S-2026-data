#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
const int N=505,M=5e5+5;
void gyx(){
    int a[M][3];
    int b[M];
    bool mp[M][3];
    memset(mp,false,sizeof(mp));
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        int num;
        for(int j=1;j<=m;j++){
            int x,y;
            cin>>x>>y;
            mp[x][i]=true;
            a[x][i]=y;
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int mn=INT_MAX;
        if(mp[u][1]==true&&mp[v][1]==true) {
            mn=min(mn,a[u][1]+a[v][1]);
        }
        if(mp[u][2]==true&&mp[v][2]==true) {
            mn=min(mn,a[u][2]+a[v][2]);
        }
        if(mn!=INT_MAX) {
            cout<<mn+b[u]+b[v]<<'\n';continue;
        }
        for(int i=1;i<=n;i++){
            if(mp[i][1]&&mp[i][2]){
                mn=min(a[i][1]+a[i][2],mn);
            }
        }
        cout<<mn+(mp[u][1]?a[u][1]:a[u][2])+(mp[v][1]?a[v][1]:a[v][2])+b[u]+b[v]<<'\n';
    }
}
int a[M];
int t[5][15];
vector<int> G[15];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c==20||c==21)    gyx();
    return 0;
}
//coded by LF Jyouhan
//Can I get back to 20-rank in the mid-term test?
