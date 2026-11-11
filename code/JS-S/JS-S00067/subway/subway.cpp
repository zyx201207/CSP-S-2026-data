#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
const ll M=1e18;
struct station{
    int cnt=0;
    int cost=0;
    int lst[5][3];
}sta[N];
struct line{
    int cnt=0;
    int lst[N];
} lines[510];
ll c,m,n,d,q,mode,mn;
bool used[505];
void dfs(int now,int des,ll cnt){
    if(now==des){
        mn=min(mn,cnt+sta[des].cost);
        return;
    }
    used[now]=1;
    for(int i=1;i<=sta[now].cnt;i++){
        int k=sta[now].lst[i][1];
        for(int j=1;j<=lines[k].cnt;j++){
            int s=lines[k].lst[j];
            if(!used[s]){
                for(int l=1;l<=sta[s].cnt;l++){
                    if(sta[s].lst[l][1]==k){
                        dfs(s,des,cnt+sta[now].lst[i][2]+sta[s].lst[l][2]);
                        break;
                    }
                }
            }
        }
    }
    used[now]=0;
    return;
}
void solve(int beg,int des){
    mn=M;
    if(beg==des){
        cout<<0<<"\n";
        return;
    }
    dfs(beg,des,sta[beg].cost);
    cout<<mn<<"\n";
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>sta[i].cost;
    }
    for(int i=1;i<=n;i++){
        cin>>lines[i].cnt;
        for(int j=1;j<=lines[i].cnt;j++){
            int a,t;
            cin>>a>>t;
            sta[a].cnt++;
            sta[a].lst[sta[a].cnt][1]=i;
            sta[a].lst[sta[a].cnt][2]=t;
            lines[i].lst[j]=a;
        }
    }
    for(int i=1;i<=q;i++){
        int x;
        int y;
        cin>>x>>y;
        solve(x,y);
    }
    return 0;
}
