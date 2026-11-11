#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],maxn=0;
void find(int i,int j,long long ans){
    if(j==m){
        maxn=max(maxn,ans);
        return ;
    }
    if(i>n) return ;
    if(ans==-1){
        find(i+1,j+1,a[i]);
        find(i+1,j,ans);
    }
    else{
        find(i+1,j+1,ans&a[i]);
        find(i+1,j,ans);
    }
    return ;
}
int f2(){
    maxn=0;
    find(1,0,(long long)-1);
    return maxn;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        cout<<f2();
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
             maxn=max(maxn,a[i]);
        }
        cout<<maxn;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
    }
    else if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==n-1){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        for(int i=1;i<=n;i++){
            long long y=ans&a[i];
            maxn=max(maxn,y);
        }
        cout<<maxn;
    }
    else{
        sort(a+1,a+n+1);
        long long ans=a[n];
        for(int i=n-1;i>=n-m+1;i--){
             ans&=a[i];
        }
        cout<<ans;
    }
    return 0;
}
