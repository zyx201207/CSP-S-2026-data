#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
bool vis[N];
int ans=-1;
int n,m;
int a[N];
int cnt[N];
void dfs(int deep,int sum,int lst){
    if(deep==m+1){
        ans=max(ans,sum);
        return;
    }
    for(int j=lst;j<=n;j++){
        if(vis[j]){
            vis[j]=false;
            if(deep==1){

                dfs(deep+1,a[j],j);

            }
            else{
                dfs(deep+1,sum&a[j],j);
            }
            vis[j]=true;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(vis,true,sizeof vis);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int summ=a[1];
    for(int i=2;i<=n;i++){
        summ&=a[i];
    }
    if(n==m){
        cout<<summ;
        return 0;
    }
    dfs(1,1,1);
    cout<<ans;
    return 0;
}
// 4 2 3 15 12 12
