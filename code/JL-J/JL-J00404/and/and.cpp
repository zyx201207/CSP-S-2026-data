#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200001];
bool b[200001];
long long ans = -1;
void dfs(long long o,long long p){
    if(o == m+1){
        ans = max(ans,p);
        return;
    }else{
        for(int i = 1;i <= n;i++){
            if(b[i] == 0){
                long long w;
                if(p == -2){
                    w = a[i];
                }else{
                    w = p & a[i];
                }
                b[i] = 1;
                dfs(o+1,w);
                b[i] = 0;
            }
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1,-2);
    cout << ans;
    return 0;
}
