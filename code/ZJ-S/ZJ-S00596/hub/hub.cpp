//CSP-S 2026 RP++!
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::ios;
using std::vector;
using std::queue;
using std::max;
using std::min;

#define int long long

const int N=1e6+6;

vector<int> vec[N],le,ch;

int n,k,c,T,ans,tim,ask_tim;
// int fa[N][30],dep[N],dfn[N];

void pre_work(){
    le.clear(),ch.clear(),ans=INT_MAX;
    for(int i=1;i<=n;i++)
        vec[i].clear();
}

// void dfs(int now,int f){
//     fa[now][0]=f,dep[now]=dep[f]+1;
//     dfn[now]=++tim;
//     for(int ne:vec[now])
//         if(ne!=f)dfs(ne,now);
//     if(vec[now].size()==1&&now!=1)
//         le.push_back(now);
// }

// bool check(int mid){
//     int mx=0,mn=n+1;
//     dfn[n+1]=n+1;
//     for(int ne:le){
//         if(dfn[ne]>dfn[mx])mx=ne;
//         if(dfn[ne]<dfn[mn])mn=ne;
//     }

// }

// void temp_solve_b(){
//     dfs(1,0);
//     for(int j=1;j<=25;j++)
//         for(int i=1;i<=n;i++)
//             fa[i][j]=fa[fa[i][j-1]][j-1];
//     int lef=0,rig=n,ans=-1;
//     while(lef<=rig){
//         int mid=(lef+rig)/2;
//         if(check(mid))rig=mid-1,ans=mid;
//         else lef=mid+1;
//     }
//     cout<<ans<<'\n';
// }

int flag[N],chk[N],fl_chc[N];

void check_dfs(int now,int fa){
    fl_chc[now]=ask_tim;
    for(int ne:vec[now]){
        if(ne==fa||!chk[ne])continue;
        check_dfs(ne,now);
    }
}

bool pre_check(){
    int tot=0;
    ask_tim++;
    for(int i=1;i<=n;i++){
        if(fl_chc[i]!=ask_tim&&chk[i])
            check_dfs(i,0),tot++;
        if(tot>=3)return false;
    }
    return true;
}

int calc(int tim){
    int res=0;
    queue<int> que,lque;
    for(int ne:ch)
        que.push(ne),lque.push(0);
    while(!que.empty()){
        int now=que.front(),len=lque.front();
        que.pop(),lque.pop();
        if(flag[now]==tim)continue;
        res=max(res,len),flag[now]=tim;
        for(int ne:vec[now]){
            if(flag[ne]==tim)continue;
            que.push(ne),lque.push(len+1);
        }
    }
    return res;
}

void decide_dfs(int now,int has){
    if(has==k){
        if(!pre_check())
            return ;
        ans=min(ans,calc(++tim));
        return ;
    }
    if(now==n+1)return ;
    chk[now]=1,ch.push_back(now);
    decide_dfs(now+1,has+1);
    chk[now]=0,ch.pop_back();
    decide_dfs(now+1,has);
}

void temp_solve_a(){
    decide_dfs(1,0);
    cout<<ans<<'\n';
}

void temp_solve(){
    pre_work();
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    temp_solve_a();
}

void solve(){
    cin>>c>>T;
    while(T--)
        temp_solve();
}

signed main(){  
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
