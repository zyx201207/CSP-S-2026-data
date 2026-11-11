#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,mmax,ans=-1;
long long arr[200002],num[42];
bool flag1=true,flag2=true;
void check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(num[i]==1)cnt++;
    }
    if(cnt==m){
        long long jg=pow(2,n+1)-1;
        for(int i=1;i<=n;i++){
            if(num[i]==1)jg&=arr[i];
        }
        ans=max(ans,jg);
    }
    return;
}
void mn(int d){
    num[d]=1;
    if(d==1){
        check();
        num[d]=0;
        check();
        return;
    }
    else{
        mn(d-1);
        num[d]=0;
        mn(d-1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]!=i-1)flag1=false;
        if(arr[i]>4)flag2=false;
    }
    sum=arr[1];
    mmax=arr[1];
    for(int i=2;i<=n;i++){
        sum&=arr[i];
        mmax=max(mmax,arr[i]);
    }
    if(m==n)cout<<sum;
    else if(m==1)cout<<mmax;
    else if(m==2){
        mmax=0;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++)
            mmax=max(mmax,arr[i]&arr[j]);
        }
        cout<<mmax;
    }
    else if(flag1){
        cout<<n-1;
    }
    else if(flag2){
        int vis[6];
        for(int i=1;i<=n;i++){
            vis[arr[i]]++;
        }
        if(vis[4]>=1){
            if(vis[1]+vis[2]+vis[3]>=m)cout<<4;
            else cout<<0;
        }
        else if(vis[3]>=1){
            if(vis[1]+vis[2]>=m)cout<<3;
            else cout<<0;
        }
        else if(vis[2]>=1){
            if(vis[1]>=m)cout<<3;
            else cout<<0;
        }
        else cout<<0;
    }
    else{
        mn(n);
        cout<<ans;
    }
    return 0;
}
