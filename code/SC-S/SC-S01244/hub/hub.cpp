#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
int c,_,n,k,fa[N],dp[N],ans[N],fin;
vector<int> p[N];
void make(int x,int fr){
    for(int y:p[x])if(y^fr)fa[y]=x,make(y,x);
}
void go(int x,int fr){
    for(int y:p[x])if(y^fr)ans[y]=min(ans[y],ans[x]+1),go(y,x);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(cin>>c>>_;_--;){
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++)cin>>u>>v,p[u-1].push_back(v-1),p[v-1].push_back(u-1);
        make(0,-1);
        fin=n;
        for(int s=0;s<(1<<n);s++){
            int cnt=0;
            for(int i=0;i<n;i++)if((s&(1<<i)&&(!(s&(1<<fa[i]))||i==0)))cnt++;
            if(cnt>1)continue;
            for(int t=0;t<(1<<n);t++){
                int ok=0;
                for(int i=0;i<n;i++)if((t&(1<<i))&&(s&(1<<i)))ok=1;
                if(ok)continue;
                int cnt=0;
                for(int i=0;i<n;i++)if((t&(1<<i)&&(!(t&(1<<fa[i]))||i==0)))cnt++;
                if(cnt>1)continue;
                cnt=0;
                for(int i=0;i<n;i++)if((t&(1<<i))||(s&(1<<i)))cnt++;
                if(cnt!=k)continue;
                for(int i=0;i<n;i++)ans[i]=n;
                int res=0;
                for(int i=0;i<n;i++)if((t&(1<<i))||(s&(1<<i)))ans[i]=0,go(i,-1);
                for(int i=0;i<n;i++)res=max(res,ans[i]);
                fin=min(fin,res);
            }
        }
        cout<<fin<<'\n';
        for(int i=0;i<n;i++)p[i].clear(),fa[i]=0;
    }
}