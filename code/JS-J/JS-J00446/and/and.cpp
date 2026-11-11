#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,m;
int ret=0;

void dfs(int cnt,int sum,int x){
    if(cnt==m){
        ret=max(ret,sum);
        return ;
    }
    for(int i=x+1;i<=n;i++){
        dfs(cnt+1,sum&a[i],i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int mx=INT_MIN;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
        return 0;
    }
    if(m==n){
        int cnt=a[1];
        for(int i=2;i<=n;i++){
            cnt&=a[i];
        }
        cout<<cnt;
        return 0;
    }
    if(n<=20||m==2){
        for(int i=1;i<=n-m+1;i++){
            dfs(1,a[i],i);
        }
        cout<<ret;
        return 0;
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}
