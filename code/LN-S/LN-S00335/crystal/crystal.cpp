//#include <bits/stdc++.h>

#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#include<stdio.h>
#include<climits>

using namespace std;

typedef long long ll;

ll n,m;
ll a[500005];

ll d[500005];

vector<ll> x;

inline bool ff(ll a){
    for(auto i:x){
        if(i==a){
            return 1;
        }
    }
    return 0;
}

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    ll diff=LLONG_MAX;
    bool flag=true;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]-a[i-1]<diff){
            diff=a[i]-a[i-1];
        }
        if(i>1){
            if(diff){
                flag=false;
            }
        }
    }
    if(flag){
        ll x=0,ans=0;
        while(x<=m){
            ans+=1;
            x+=diff*(ans-1);
        }
        printf("%lld",ans);
        return 0;
    }
    ll min_d=LLONG_MAX;
    ll id=-1;
    d[1]=LLONG_MAX;
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        if(d[i]<=min_d){
            min_d=d[i];
            id=i;
        }
    }
    ll ans=0;
    while(m>=0){
        x.push_back(id);
        for(ll i=2;i<=n;i++){
            if(d[i]==0){
                for(ll j=i;j<=n;j++){
                    if(d[j]!=0){
                        ans=max(ans,j-i+1);
                        break;
                    }
                }
            }
        }
        m-=d[id];
        d[id-1]+=d[id];
        d[id]=0;
        min_d=LLONG_MAX;
        for(int i=2;i<=n;i++){
            if(!ff(i)&&d[i]<=min_d){
                min_d=d[i];
                id=i;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
