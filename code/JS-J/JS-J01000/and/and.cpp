#include <bits/stdc++.h>
using namespace std;

int n, m, idx=0, ans, max_ans=0;
int a[200001];
//int dp[200001][200001];


void dfs(int last, int t){
    if(ans<=max_ans) {
        // cout<<"/"<<endl;
        return;
    }
    if(t==m){
        // cout<<111;
        // cout<<"->"<<ans<<endl;
        max_ans = max(ans, max_ans);
        return;
    }
    int ans0 = ans;

    for(int i=last+1;i<=n;i++){
        ans&=a[i];
        // cout<<a[i]<<" ";
        dfs(i, t+1);
        ans=ans0;
    }
}


int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    ans = 2147483647;
    dfs(0, 0);

    cout<<max_ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
