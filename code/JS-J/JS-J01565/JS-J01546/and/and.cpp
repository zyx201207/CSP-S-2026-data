#include <bits/stdc++.h>
using namespace std;
int n,m;
long long s[200005],col[200005];
int sumup(){
    int ans = col[1];
    for(int i=2;i<=m;i++){
        ans = ans&col[i];
    }
    return ans;
}
int dfs(int lay,int x){
    if(lay==m+1){
        return sumup();
    }
    long long ans = 0;
    for(int i=x+1;m-lay+1<=n-i+1;i++){
        col[lay] = s[i];
        if(dfs(lay+1,i)>ans){
            ans = dfs(lay+1,i);
        }
    }
    return ans;
}
int main(){
    /*freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);*/
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    cout<<dfs(1,0);
    return 0;
}
