#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,mmax;
ll a[500050]={};
ll check(ll k){
    //ans是最多的合并参与者数量，num是剩余的操作次数
    ll ans=1,num=m;
    for(long long i=k+1;i<n;i++){
        //nn是本次合并所需的操作
        ll nn=ans*(a[i]-a[i-1]);
        if(nn<=num){
            num-=nn;
            ans++;
        }else if(nn>num){
            break;
        }

    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);/*
    //性质A特判
    bool test1=1;
    for(int i=0;i<n;i++){
        if(a[i]!=i){
            test1=0;
            break;
        }
    }
    if(test1==1){
        ll aans=0;
        for(int i=0;i<n;i++){
            aans+=a[i];
            if(aans>m){
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    //性质B特判
    bool test2=1;
    for(int i=0;i<n;i++){
        if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
            test2==0;
        }
    }
    if(test2==1){
        ll anns=0;
        for(int i=0;i<n;i++){
            anns+=i*(a[1]-a[0]);
            if(anns>m){
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }*/
    //尝试n次，每次从a[k]开始
    for(ll k=0;k<n;k++){
        mmax=max(check(k),mmax);
    }
    cout<<mmax;
    return 0;
}
