#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1919810],t[1919810],ans;
void dfs(int step,int num){
    t[step]=a[num];
    if(step>=m){
        int sum=t[1];
        for(int i=1;i<=m;i++){
            sum&=t[i];
        }
     //   if(sum==15) cout<<t[1]<<" "<<t[2]<<endl;
        ans=max(ans,sum);
        return;
    }
    for(int i=num+1;i<=n;i++){
        dfs(step+1,i);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}
