#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int li[500010],lst[300010],cnt[300010],ans[300010];
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> li[i];
        lst[li[i]] = i;
        cnt[li[i]]++;
    }
    for(int num = 1;num <= m;num++){
        for(int i = lst[num];i <= n;i++){
            i = lst[li[i]];
            ans[li[i]] += cnt[num];
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
3 1
1: 10
2: 3
3: 3
*/