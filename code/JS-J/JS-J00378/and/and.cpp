#include<bits/stdc++.h>
using namespace std ;
#define int long long
int n,m,a[1010101],cnt=-1e18;
int dfs(int i,int c,int h){
    if(c==m){

        cnt=max(cnt,h);

        return 0;
    }
    if(i>n){
        return 0;
    }
    dfs(i+1,c+1,h&a[i]);
    dfs(i+1,c,h);
    return 0;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    dfs(1,0,pow(8,10)-1);

    cout<<cnt;
    return 0;
}
