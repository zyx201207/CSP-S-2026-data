#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5;
int c,m,n,d,q,a[maxn],ans=1e9;
struct Node{
    int station;
    int time;
}st[maxn][10];
vector<int>G[maxn];
vector<int>R[maxn];
void bfs(int s,int e,int pos,int sum,int xi){
    if(pos==e){
        ans=min(ans,sum);
        return;
    }
    for(auto x:G[pos]){
        if(x==pos) continue;
        for(auto p:R[x]){
            if(p==xi) continue;
            bfs(s,e,x,sum+st[xi][pos].time+st[xi][p].time,p);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1,len;i<=n;i++){
        cin>>len;
        for(int j=1,s,t;j<=len;j++){
            cin>>s>>t;
            st[i][j].station=s;
            st[i][j].time=t;
            G[i].push_back(s);
            R[s].push_back(i);
        }
    }
    for(int i=1,l,r;i<=q;i++){
        ans=1e9;
        cin>>l>>r;
        for(auto x:R[l]) bfs(l,r,l,0,x);
        cout<<ans<<"\n";
    }
    return 0;
}
