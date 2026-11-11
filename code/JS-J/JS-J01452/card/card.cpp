//10:18 start
#include<bits/stdc++.h>
using namespace std;

struct node{
    int to, value;
    vector<int> sons;
};

int n = 0, m = 0, last[300010], a[500010];
node ans[300010];
bool vis[300010];

int dfs(int x){
    for(int i = 0;i < ans[x].sons.size();i++){
        ans[x].value += dfs(ans[x].sons[i]);
    }
    //cout << ans[x].value << " " << x << endl;
    return ans[x].value;
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        last[a[i]] = i;
        ans[a[i]].value++;
    }
    int x = 1;
    vis[a[n]] = true;
    //make tree
    for(int i = n - 1;i >= 1;i--){
        if(vis[a[i]] == false){
            vis[a[i]] = true;
            ans[a[i]].to = a[i + 1];
            ans[a[i + 1]].sons.push_back(a[i]);
            x++;
            if(x == m){
                break;
            }
        }
    }
    ans[a[n]].value = dfs(a[n]);
    for(int i = 1;i <= m;i++){
        cout << ans[i].value << " ";
    }
    return 0;
}


//kale
//10:30 you si lu le
//11:11 OHHHHHHHH(AC)
//11:31 last,ans,vis[100010] -> [300010]  a[200010] -> [500010]
