#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int csd,t,n,k,ans = INT_MAX,sum;
vector <int> G[N];
int p[N],c[N],vis[N],d[N],P[N],fa[N];

void init(int u,int dep){
    for(auto v : G[u]){
        if(vis[v] || d[v] == 0) continue;
        vis[v] = 1;
        d[v] = min(d[v],dep + 1);
        init(v,dep + 1);
    }
    return ;
}

void dfs2(int A,int B,int cnt,int dep,int last){
    if(dep > k - 2){
        c[k - 1] = A;
        c[k] = B;


        for(int i=1;i<=n;i++)
            d[i] = INT_MAX;
        for(int i=1;i<=k;i++)
            d[c[i]] = 0;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++)
                vis[j] = 0;
            vis[c[i]] = 1;
            init(c[i],0);
        }

        sum = 0;
        for(int i=1;i<=n;i++)
            sum = max(d[i],sum);
        //cout<<sum<<endl;
        /*if(sum == 2){
            cout<<"example::"<<endl;
        for(int i=1;i<=k;i++)
                cout<<c[i]<<" ";
            cout<<endl;
        }*/
        ans = min(sum,ans);
        return ;
    }
    if(fa[A] == B || fa[B] == A){
        for(int i = last + 1;i <= n + dep - (k - 2);i++){
            c[dep] = i;
            dfs2(A,B,cnt,dep + 1,i);
        }
    }
    else{
        for(int i = last + 1;i <= cnt + dep - (k - 2);i++){
            c[dep] = P[i];
            dfs2(A,B,cnt,dep + 1,i);
        }

    }
}

void dfs(int dep,int last){
    if(dep > 2){
        int A = p[1],B = p[2],cnt = 0;
        //cout<<"A:B:"<<A<< " "<<B<<endl;
        /*if(A == 1 && B == 2){
            for(int i=1;i<=cnt;i++)
                cout<<P[i]<<" ";
            cout<<endl;
        }*/
        if(fa[A] != B && fa[B] != A){
            for(auto u : G[A])
                P[++cnt] = u;
            for(auto u : G[B])
                P[++cnt] = u;
        }
        dfs2(A,B,cnt,1,0);
        return ;
    }
    for(int i=last + 1;i<=n+dep-2;i++){
        p[dep] = i;
        dfs(dep + 1,i);
    }
}

void in(int u,int f){
    for(auto v : G[u]){
        if(v == f) continue;
        fa[v] = u;
        in(v,u);
    }
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>csd>>t;
    while(t --){
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        in(1,0);
        ans = INT_MAX;
        dfs(1,0);
        for(int i=1;i<=n;i++)
            G[i].clear();
        cout<<ans<<endl;
    }
    return 0;
}
