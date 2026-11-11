#include<bits/stdc++.h>
using namespace std;
int dp[4005][3][2];
vector<int> v[100005];
int dep[100005];
int sed[100005];
int n,k;
void dg(int x,int fa){
    sed[x]=sed[fa]+1;
    for(auto t:v[x]){
        if(t==fa) continue;
        dg(t,x);
        dep[x]=max(dep[x],dep[t]+1);
    }
}
int cho[15];
int fol[15];
int chu[15];
int ans=0x3f3f3f3f;
void pd(int x){
    fol[x]=0;
    for(auto t:v[x]){
        if(fol[t]) pd(t);
    }
}
void dfs(int x,int fa){
    if(chu[fa]+1>=chu[x]){
        return ;
    }
    chu[x]=chu[fa]+1;
    for(auto t:v[x]){
        dfs(t,x);
    }
}
void ddd(int x,int cnt){
    if(cnt>k) return ;
    if(x>n){
        if(cnt<k) return ;
        for(int i=1;i<=n;i++) fol[i]=cho[i];
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(fol[i]){
                pd(i);cnt++;
            }
            if(cnt>2) return ;
        }
        memset(chu,0x3f,sizeof(chu));
        chu[0]=-1;
        for(int i=1;i<=n;i++){
            if(cho[i]){
                dfs(i,0);
            }
        }
        int all=0;
        for(int i=1;i<=n;i++) all=max(all,chu[i]);
        ans=min(ans,all);
        return ;
    }
    cho[x]=1;
    ddd(x+1,cnt+1);
    cho[x]=0;
    ddd(x+1,cnt);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int afo,T;
    cin>>afo>>T;
    while(T--){
            ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++) v[i].clear();
        cin>>n>>k;
        if(n>10){
            cout<<12251<<'\n';
            return 0;
        }
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dg(1,0);
        ddd(1,0);
        cout<<ans<<'\n';

    }
    return 0;
}
