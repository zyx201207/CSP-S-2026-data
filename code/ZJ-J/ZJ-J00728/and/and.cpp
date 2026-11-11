#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m,a[N],ans=INT_MIN;
int mp[N][39];
void init(int x,int k){
    int len=1;
    while(x>0){
        mp[k][len]=x%2;
        len++;
        x/=2;
    }
}
void dfs(int x,int res){
    if(x>m) {
        ans=max(ans,res);
        return;
    }
    for(int i=x+1;i<=n-m+1+x;i++){
        dfs(x+1,res&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        init(a[i],i);
    }
    for(int i=1;i<=n-m+1;i++){
        dfs(1,a[i]);
    }
    cout<<ans;
    return 0;
}
