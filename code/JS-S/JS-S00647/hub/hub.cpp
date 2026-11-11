#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6+5;
vector<int>ve[N];
int num[N],f[N];
int vis[N],p[N];
int minn=1e18;
int len[N];
int find(int k){
    if(k==f[k]){
        return k;
    }
    return f[k]=find(f[k]);
}
void sdfs(int now){
    for(auto x:ve[now]){
        if(p[x] && x!=now){
           vis[x]=1;
           sdfs(x);
        }
    }
    return;
}
int dlen(int now,int f){
    int len[now]=len[f]+1;
    int maxn=len[now];
    for(auto x:ve){
        if(p[x]==0){
            maxn=max(maxn,dlen(x,now));
        }
    }
    return maxn;
}
void dfs(int now,int l,int s){
    if(now>l){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(p[i] && vis[i]==0){
                vis[i]=1;
                sdfs(i);
                cnt++;
            }
        }
        if(cnt>=1 && cnt<=2){
            int sum=1e18;
            for(int i=1;i<=n;i++){
                if(p[i]){
                    for(int i=1;i<=n;i++){
                        len[i]=1e18;
                    }
                    len[0]=-1;
                    sum=max(sum,dlen(i,0));
                }
            }
            minn=min(minn,sum);
        }
        for(int i=1;i<=n;i++){
            vis[i]=0;
        }
    }
    if(s<k){
        p[now]=1;
        dfs(now+1,n,s+1);
        p[now]=0;
        dfs(now+1,n,s);
    }
    else{
        dfs(now+1,n,s);
    }
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c,T;
    cin>>c>>T;
    int n,k;
    while(T--){
        cin>>n>>k;
        int u,v;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            ve[u].push_back(v);
            ve[v].push_back(u)
        }
        minn=1e18;
        dfs(1,n,0);
        if(k==n){
            cout<<0<<"\n";
            continue;
        }
        cout<<minn<<"\n";
    }
    return 0;
}
