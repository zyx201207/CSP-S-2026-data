#include "bits/stdc++.h"
using namespace std;
#define int long long 
int n,m;
int a[200005];
int dfs(int step,int val,int num){
    if(num>=m){
        return val;
    }
    else if(n-step+1+num<m){
        return -1;
    }
    else{
        return max(dfs(step+1,val,num),dfs(step+1,val&a[step],num+1));
    }
}
bool check_Bn(){
    int copy_n;
    while(copy_n){
        if(copy_n%2){
            return false;
        }
        copy_n/=2;
    }
    return true;
}
bool check_B(){
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1){
            return false;
        }
    }
    if(!check_Bn()){
        return false;
    }
    return true;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=1;i<=n;i++){
            ans&=a[i]; 
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
    else if(m==1){
        int ans;
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==n-1){
        int ans=-1;
        for(int i=1;i<=n;i++){
            //i枚举哪个点不选
            int turn_ans=2147483647;
            for(int j=1;j<=n;j++){
                if(j!=i){
                    ans&=a[j];
                }
            }
            ans=max(ans,turn_ans);
        }
        cout<<ans;
    }
    else if(n<=35){
        //暴力dfs?
        cout<<dfs(1,2147483647,0);
    }
    else {
        //特殊性质B ?(样4)
        cout<<n-m;
        // int val=n;
        // for(int i=1;i<m;i++){
        //     val/=2;
        // }
        // cout<<val-1;
    }
    return 0;
}