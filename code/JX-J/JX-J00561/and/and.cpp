#include<bits/stdc++.h>
using namespace std;
long long a[200001]={},cha[200001]={},qian[200001]={};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cha[i]=a[i]-a[i-1];
        qian[i]=cha[i]+qian[i-1];
    }
    long long mi=1e18,mii=0;
    for(int i=n-m+1;i<=n;i++){
        if(qian[i]-qian[i-m]<mi){
            mi=qian[i]-qian[i-m];
            mii=i;
        }
    }
    long long ans2=a[mii];
    //cout<<ans2<<" ";
    for(int i=mii-m+1;i<mii;i++){
        ans2=ans2&a[i];
        //cout<<a[i]<<" ";
    }
    if(ans2==0){
        mii-=1;
        ans2=a[mii];
        for(int i=mii-m+1;i<mii;i++){
            ans2=ans2&a[i];
        }
    }
    long long ans1=a[n];
    //cout<<a[n]<<" ";
    for(int i=n-1;i>=n-m+1;i--){
        ans1=ans1&a[i];
       // cout<<a[i]<<" ";
    }
    if(ans1==0){
       long long ans1=a[n-1];
        //cout<<a[n]<<" ";
        for(int i=n-2;i>=n-m;i--){
            ans1=ans1&a[i];
        // cout<<a[i]<<" ";
        }
    }
    cout<<max(ans1,ans2);
    return 0;
}
