#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int n,m;
long long ans=0,ans1=0;
void dfs(int now,int siz,long long mx){
    if(siz==m&&now<=n){
        ans=max(ans,mx);
        return ;
    }
    if(now>n)return ;
    dfs(now+1,siz,mx);
    if(mx==0){
        dfs(now+1,siz+1,a[now]);
    }
    else{
        dfs(now+1,siz+1,mx&a[now]);
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=20){
       dfs(0,0,0);
       cout<<ans;
    }

    else if(n==m){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==1){
        cout<<a[n];
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n-1){
        ans=a[2];
        ans1=a[1];
        for(int i=3;i<=n;i++){
            ans&=a[i];
            ans1&=a[i];
        }
        cout<<max(ans,ans1);
    }
    else{
        ans=a[n];
        for(int i=n-1;i>n-m;i--){
            ans&=a[i];
        }
        cout<<ans;
    }
    return 0;
}
