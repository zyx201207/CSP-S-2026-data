#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+1;
int n,m;
int a[N];
int ans=-99999999;
void dfs(int i,int t,int s){
    if(i==n+1){
        if(t==m){
            ans=max(ans,s);
        }
        
        return;
    }
    if(t==0){
        dfs(i+1,1,a[i]);
    }else{
        if(t!=m){
            dfs(i+1,t+1,s&a[i]);
        }
       
        dfs(i+1,t,s);
    }
    
    

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(nullptr);ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }else if(m==2){
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            int k=a[i+1];
            for(int j=1;j<=n;j++){
                if(j==i){
                    continue;
                }
                k&=a[j];
            }
            ans=max(ans,k);
        }
        cout<<ans;
        return 0;
    }
    if(n<=20){
        for(int i=1;i<=n;i++){
            dfs(i,0,a[i]);
        }
        cout<<ans;
        return 0;
    }

    return 0;
}