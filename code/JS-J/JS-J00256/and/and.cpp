#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int n,m;
int a[2000005];
int sum=-1;
void dfs(int depth,int ans,int k){
    if((depth==n+1)&&(k==m)){
        if(ans>=sum){
            sum=ans;
            return ;
        }
    }
    if(depth==n+1&&k!=m){
        return ;}
    if(k<m){
        dfs(depth+1,ans&a[depth],k+1);
    }
    dfs(depth+1,ans,k);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    if(m==1){
        sort(a+1,a+1+n,cmp);
        cout<<a[1];
    }
    else if(m==n){
            int ans=1;
        for(int i=1;i<=n;i++){
            ans=a[i]&ans;
        }
        cout<<ans;
    }
    else if(m==2){
        int ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){

                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else{
            dfs(1,1,0);
        cout<<sum;
    }
    return 0;
}
