#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll dfs(int cnt,vector<int>ok){
    if(cnt<0) return 0;
    vector<int>now;
    for(int i=0;i<(int)ok.size();i++){
        if((ok[i]>>cnt)&1) now.push_back(ok[i]);
    }
    if(now.size()>=m){
        return (1LL<<cnt)+dfs(cnt-1,now);
    }
    return dfs(cnt-1,ok);
}
int main(){
    freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<dfs(30,a);
    return 0;
}
