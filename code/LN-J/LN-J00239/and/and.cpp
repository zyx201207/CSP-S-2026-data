#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long mx;
void dfs(int x,int y,long long sum){
    if(x>n){
        if(y==m){
            mx=max(mx,sum);
            return ;
        }
        return ;
    }
    if(y==0){
        dfs(x+1,y,sum);
        dfs(x+1,y+1,sum+a[x]);
        return ;
    }
    dfs(x+1,y,sum);
    dfs(x+1,y+1,sum&a[x]);
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<mx;
    return 0;
}
