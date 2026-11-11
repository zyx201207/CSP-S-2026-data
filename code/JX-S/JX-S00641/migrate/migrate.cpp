#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,ans=1e9;
int n,d;
void dfs(int i,int sum){
    if(i==n){
        if(ans==sum){
            d++;
        }
        ans=min(sum,ans);
        return;
    }
    if(i>n){
        return;
    }
    for(int j=1;j<d;j++){
        dfs(i+j,sum+1);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int a[n];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=0;
        dfs(1,0);
        cout<<d<<endl;
    }
    return 0;
}
