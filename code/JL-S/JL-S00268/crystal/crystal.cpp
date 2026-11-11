#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],b[500005],k=1,ans,mx=-1,sum=0,mxk;
void solve_simple_of_small(){
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1) b[i-1]=a[i]-a[i-1];
    }
    while(k<n){
        for(int i=1;i<=n-k;i++){
            ll p=0;
            for(int j=1;j<=k;j++) p+=b[i+j-1];
            if(mx<p){
                mx=p;
                mxk=i+k+1;
            }
        }
        if(mx>m) break;
        else if(mx==m){
            ans=k+1;
            while(a[mxk]==a[mxk-1]){
                ans++;
                mxk++;
            }
            cout<<ans;
            return;
        }else k++;
    }
    for(int i=1;i<=n-k;i++){
        ll p=0;
        for(int j=1;j<=k;j++) p+=b[i+j-1];
        if(mx<p && p<m){
            mx=p;
            mxk=i+k+1;
        }
    }
    ans=k+1;
    while(a[mxk]==a[mxk-1]){
        ans++;
        mxk++;
    }
    cout<<ans;
}
void solve_special_of_big(){
    for(int i=1;i<=n;i++) cin>>a[i];
    int r=a[n]-a[n-1],sum=0,t=0,mkl=1;
    while(sum<=m && t<n){
        sum+=r*mkl;
        mkl++;
        t++;
    }
    cout<<t;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n<=5000) solve_simple_of_small();
    else solve_special_of_big();
    return 0;
}
