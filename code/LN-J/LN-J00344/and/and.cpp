#include<bits/stdc++.h>
using namespace std;
int dp[262144];
int pw[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,
            16384,32768,65536,131072,262144,524288,1048576,
            2097152,4194304,8388608,16777216,33554432,67108864,
            134217728,268435456,536870912,1073741824};
set<int> v[32];
struct node{
    int num;
    int id;
} a[262144];
void to_bin(node nn){
    int n = nn.num;
    int id = nn.id;
    for(int i=0;i<=31&&n;i++){
        if(n&1){
            v[i].insert(id);
        }
        n >>= 1;
    }
    return ;
}
set<int> INT(set<int> a, set<int> b){
    set<int> res;
    b.insert(11451444);
    for(auto r : a){
        if(b.find(r) != b.end()){
            res.insert(r);
        }
    }
    /*for(auto r : b){
        if(b.find(r) != a.end()){
            res.insert(r);
        }
    }*/
    return res;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i].num;
        a[i].id = i;
        to_bin(a[i]);
    }
    int cnt = 114514;
    for(int i=31;i>=0;i--){
        if(v[i].size() >= m){
            cnt = i;
            break;
        }
    }
    if(cnt == 114514){
        cout<<0;
        return 0;
    }
    set<int> ans = v[cnt];
    vector<int> sss;
    sss.push_back(cnt);
    for(int i=cnt-1;i>=0;i--){
        if(v[i].size() >= m){
            ans = INT(ans, v[i]);
            sss.push_back(i);
        }
    }
    if(ans.size() >= m){
        int res = 0;
        for(int i=0;i<sss.size();i++){
            res += pw[sss[i]];
        }
        cout<<res<<endl;
        return 0;
    }
    else{
        int res = 2147483647;
        for(auto r : ans){
            res &= a[r].num;
        }
        int need = m - ans.size();
        for(auto r : v[cnt]){
            if(ans.find(r) == ans.end()){
                res &= a[r].num;
                need --;
                if(!need){
                    cout<<res<<endl;
                    return 0;
                }
            }
        }
        return 0;
    }
    /*dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            cout<<(dp[j-1]&v[i])<<endl;
            dp[i] = max(dp[j], dp[j-1]&v[i]);
        }
    }
    cout<<dp[m]<<endl;*/

    return 0;
}
