#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int a[N];
int n,m;
int ans;
void dfs(int x,int sum,int s){
    if(x==n+1){
        if(sum==m){
            ans=max(ans,s);
        }
        return;
    }
    dfs(x+1,sum+1,s&a[x]);
    dfs(x+1,sum,s);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
    }else if(m==n){
        ans=(2<<30)-1;
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
            int sum=1;
            for(int j=1;j<=n;j++){
                if(j!=i){
                    sum=sum&a[j];
                }
            }
            ans=max(ans,sum);
        }
    }else if(n>2000){
        sort(a+1,a+1+n);
        ans=(2<<30)-1;
        for(int i=n;i>n-m;i--){
            ans=ans&a[i];
        }
    }else{
        dfs(1,0,(2<<30)-1);
    }
    cout<<ans<<endl;
    return 0;
}
