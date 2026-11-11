#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int maxnum = 0;
int nums[1008611];
// bool went[1008611];

void dfs(int now, int cnt, int num){
    if(cnt == m){
        num &= nums[now];
        maxnum = max(maxnum, num);
        return;
    }

    for(int i = now + 1;i <= n;i++){
        dfs(i, cnt + 1, num & nums[i]);
    }
}

signed main(){
    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        cin >> nums[i];
    }

    dfs(0, 0, -1);

    cout << maxnum << endl;
}
