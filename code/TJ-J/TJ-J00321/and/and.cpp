#include<iostream>
#include<algorithm>
using namespace std;
int maxx = -1;
int n,m,a[200005],candicate[200005];
int binary(int x){
    int cnt = 0;
    while(x){
        if(x % 2 == 1)cnt++;
        x /= 2;
    }
    return cnt;
}
void dfs(int depth,int pos){
    if(depth == m+1){
        int ans = candicate[1];
        for(int i = 2;i <= m;i++){
            ans = ans & candicate[i];
        }
        maxx = max(maxx,ans);
        return;
    }
    for(int i = pos;i <= n;i++){
        candicate[depth] = a[i];
        dfs(depth+1,i+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dfs(1,1);
    cout << maxx;
    return 0;
}
