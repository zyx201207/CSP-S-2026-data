#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200020];
int ans[200020];
priority_queue<int , vector<int> > q;
map<int,bool> vis;
map<pair<int,int>,int> memo;
//int maxa = 0;
void dfs(int step){
    if(step > m){
        int sum = ans[1];
        for(int i = 2 ; i <= m ; i++){
            if(memo[{sum,ans[i]}]) sum = memo[{sum,ans[i]}];
            else{
                memo[{sum,ans[i]}] =sum & ans[i];
                sum = memo[{sum,ans[i]}];
            }
        }

        //for(int i = 1 ; i <= m ; i++) cout << ans[i] << ' ';
        //maxa = max(maxa,sum);
        //cout << '\n';
        q.push(sum);
        return;
    }
    for(int i = 1 ; i <= n ; i++){
        if(vis[a[i]]) continue;
        ans[step] = a[i];
        vis[a[i]] = true;
        dfs(step+1);
        vis[a[i]] = false;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    //memo.resize(int(pow(2,30)));
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    dfs(1);
    //cout << maxa;
    cout << q.top();
    return 0;
}

// I AK CSP-J!
