#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
typedef long long LL;
int a[N],dp[N],lst[N],nxt[N],tail[N];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(lst,0x3f,sizeof lst);
    memset(nxt,0x3f,sizeof nxt);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i],dp[i] = 1;
    for(int i = n;i >= 1;i--){
        nxt[i] = lst[a[i]];
        lst[a[i]] = i;
        if(!tail[a[i]]) tail[a[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        if(nxt[i] != 0x3f3f3f3f)    dp[nxt[i]] += dp[i];
        else    dp[i+1] += dp[i];
    }
    for(int i = 1;i <= m;i++){
        cout << dp[tail[i]] << ' ';
    }
    return 0;
}