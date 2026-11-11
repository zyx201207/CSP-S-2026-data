#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int id,w;
};
int c,n,m,d,q;
int w[500010];
int arr[510][510];
vector<node> ve1[500010],ve2[510];
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++) {
        scanf("%lld",&w[i]);
    }
    for(int i = 1;i <= n;i++) {
        int k; scanf("%lld",&k);
        for(int j = 1;j <= k;j++) {
            int a,t; scanf("%lld%lld",&a,&t);
            ve1[a].push_back({i,t});
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(i != j) arr[i][j] = 1e18;
        }
    }
    for(int i = 1;i <= m;i++) {
        for(int j = 0;j < ve1[i].size();j++) {
            for(int k = j + 1;k < ve1[i].size();k++) {
                if(j != k) {
                    node x = ve1[i][j],y = ve1[i][k];
                    arr[y.id][x.id] = arr[x.id][y.id] = min(arr[x.id][y.id],x.w + y.w);
                }
            }
        }
    }//O(m*d^2)
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = i + 1;j <= n;j++) {
                arr[j][i] = arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
            }
        }
    }//O(n^3)
    while(q--) {
        int st,ed; scanf("%lld%lld",&st,&ed);
        int ans = 1e18;
        for(int i = 0;i < ve1[st].size();i++) {
            for(int j = 0;j < ve1[ed].size();j++) {
                ans = min(ans,arr[ve1[st][i].id][ve1[ed][j].id] + ve1[st][i].w + ve1[ed][j].w + w[st] + w[ed]);
            }
        }
        printf("%lld\n",ans);
    }//O(q*d^2)
    fclose(stdin);
    fclose(stdout);
    return 0;
}
