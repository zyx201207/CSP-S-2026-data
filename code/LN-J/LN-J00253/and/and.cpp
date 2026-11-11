#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,maxn=0,a[N];
long long ans;
bool flag[N];
void dfs(long long depth,long long ans){
    if (depth==m){
        maxn=max(ans,maxn);
        return ;
    }
    for (int i=1;i<=n;i++){
        if (flag[i]){
            flag[i] = false;
            int ans_t=ans;
            ans_t&=a[i];
            dfs(depth+1,ans_t);
            flag[i]=true;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    memset(flag,true,sizeof(flag));
    for (int i=1;i<=n;i++){
        flag[i]=false;
        dfs(1,a[i]);
        flag[i]=true;
    }
    cout << maxn;
    return 0;
}
