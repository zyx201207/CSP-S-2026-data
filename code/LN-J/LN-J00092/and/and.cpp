#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int B=pow(2,31)-1;
int n,m;
int a[N];
int ans=0;
void dfs(int id,int k,int sum){
    if(k==m){
        ans=max(ans,sum);
        return ;
    }
    for(int i=id+1;i<=n;i++){
        dfs(i,k+1,sum&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    bool typeC=true,typeA=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i]!=a[i-1])typeC=false;
        if(__builtin_popcount(a[i]+1)!=1)typeA=false;
    }
    if(typeC)cout<<a[1];
    else if(typeA){
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }else if(m==1){
        int ma=a[1];
        for(int i=2;i<=n;i++)ma=max(ma,a[i]);
        cout<<ma;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if(n<=20){
        dfs(0,0,B);
        cout<<ans;
    }else{
        cout<<a[1];
    }
    return 0;
}
