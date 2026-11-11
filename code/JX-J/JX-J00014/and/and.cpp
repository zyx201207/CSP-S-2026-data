#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;

const int N = 2e5 + 6;
int arr[N];

int ans = 0;

void dfs(int s,int idx,int cnt){
    if(idx > n) return;
    if(cnt == m){
        ans = max(ans,s);
        return;
    }
    dfs((s & arr[idx]),idx + 1,cnt + 1);
    dfs(s,idx + 1,cnt);
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;

    for(int i = 1;i <= n;i ++) cin >> arr[i];

    sort(arr + 1,arr + n + 1,greater<int>());

    int p = 1;
    for(int i = 1;i <= 30;i ++) p <<= 1;

    p --;
    dfs(p,1,0);

    cout << ans;
    return 0;
}