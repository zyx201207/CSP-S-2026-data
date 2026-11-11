#include<bits/stdc++.h>
using namespace std;

int dfs(int &now,int&ls,long long ans,long long &m,long long h){
    h++;
    ans &= ls[now];
    if(m==h)return ans;
    for(int i = 0; i < n;i++){
        v = max(dfs(i,ls,ans,m),v);
    }
    ans = max(ans,v);
    return ans;
}

int main(){
    freopen("and.in","r",stdin);
    int n,m;
    cin >>n >> m;
    vector<int>ls;
    for(int i = 0;i < n;i){
        cin >> ls[i];
    }
    freopen("and.out","w",stdout);
    cout << dfs(0,ls,0,m,0);
    return 0;
}
