#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N = 5e5+10;

int n,m;
int a[N];
int las[N];
int f[N];//How many is this 'i' use
bool b[N];
int ans[N];
vi g[N];
inline void dfs(int x){
    f[x] = 1;
    for (auto y : g[x]){
        dfs(y);
        f[x] += f[y];
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        las[a[i]] = i;
    }
    for (int i = 1;i <= n;i++){
        g[las[a[i]]+1].push_back(i);
    }
    dfs(n+1);
    for (int i = 1;i <= n;i++){
        ans[a[i]] += f[i];
    }
    for (int i = 1;i <= m;i++){
        printf("%lld ",ans[i]);
    }
    printf("\n");
  

    return 0;
}