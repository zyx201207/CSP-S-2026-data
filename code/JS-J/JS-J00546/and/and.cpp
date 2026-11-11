#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,m;
unordered_set<int> bitnum[40],ans;
int check(unordered_set<int>&a,unordered_set<int>&b){
    int ret=0;
    for(auto&x:a) if(b.count(x)) ret++;
    return ret;
}
void update(unordered_set<int>&a,unordered_set<int>&b){
    for(auto x:a) if(!b.count(x)) a.erase(x);
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        ans.insert(x);
        for(int j=0;(1<<j)<=x;j++) if((1<<j)&x) bitnum[j].insert(x);
    }
    for(int i=30;i>=0;i--){
        if(check(ans,bitnum[i])<m) continue;
        update(ans,bitnum[i]);
        if(ans.size()==m) break;
    }
    int num=(1U<<31)-1;
    for(auto&x:ans){num&=x;cout<<x<<' ';}
    cout<<num;
    return 0;
}
