#include<bits/stdc++.h>
using namespace std;

queue<int> que;
int n,m,q;
vector<int> w,k;
vector<vector<int>> a,t;

// int work(int u,int v)
// {
//     que.push(u);
//     vector<bool> v(m);
//     v[u] = true;
//     while(true) {
//         int now = que.front();
//         que.pop();
//         for(int q:)
//     }
// }

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&n,&n,&m,&m,&q);
    w.resize(m),k.resize(m);
    a.resize(m),t.resize(m);
    for(int i=0;i<m;i++) {
        scanf("%d",&w[i]);
    }
    for(int i=0;i<m;i++) {
        scanf("%d",&k[i]);
        a[i].resize(k[i],0);
        t[i].resize(k[i],0);
        for(int j=0;j<t[i];j++) {
            scanf("%d %d",&a[i][j],&t[i][j]);
        }
    }
    for(int i=0;i<q;i++) {
        int u,v;scanf("%d %d",&u,&v);
        printf("%d\n"a[u][v]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*

    // const int MAXNUM = 1e9;
    // const int MAXM = 5e5+10;
    // const int MAXN = 800;
    // int n,m,q;
    // int w[MAXM];
    // int k[MAXM];
    // int a[MAXN][MAXM];
    // int t[MAXN][MAXM];
    // vector<vector<int>> g;
    
    // long long ans;
    // int u,v;
    
    // vector<bool> vec;
    
    // void dfs(int now,int sum)
    // {
    //     if(now == v) {
    //         ans = min(ans,(long long)(sum+w[u]+w[v]));
    //         return ;
    //     }
    //     for(int nxt:g[now]) {
    //         if(!vec[nxt]) {
    //             vec[nxt] = true ;
    //             dfs(nxt,sum+t[now][nxt]);
    //             vec[nxt] = false;
    //         }
    //     }
    // }
    
    
    // scanf("%d %d %d %d %d",&n,&n,&m,&m,&q);
    // for(int i=1;i<=m;i++) {
    //     scanf("%d",&w[i]);
    // }
    // for(int i=1;i<=n;i++) {
    //     scanf("%d",&k[i]);
    //     for(int j=1;j<=k[i];j++) {
    //         scanf("%d %d",&a[i][j],&t[i][j]);
    //     }
    // }
    // for(int i=1;i<=q;i++) {
    //     scanf("%d %d",&u,&v);
    //     vec.resize(m,0);
    //     ans = MAXNUM;
    //     dfs(u,0);
    //     printf("%lld\n",ans);
    // }

*/
// hspng
