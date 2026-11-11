#include<bits/stdc++.h>
#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
ll a[500005],n,m,cnt,ans,sum=1,mx=0;
ll f(int x){
    ll gch=1;
        for(int i=x-1;i>=1;i--){

            if(cnt+a[x]-a[i]>m){
                break;
            }else{
                cnt+=a[x]-a[i];
                gch++;
            }

        }
    return gch;
}
int main(){


    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i){
            cnt++;
        }

    }
    ll y=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]==y){
            sum++;
        }
    }
    ll x=0;
    if(cnt==n){
        while(ans<=m){
            x++;
            ans+=x;

        }
        if(x>n){
            cout<<n;
        }else{
            cout<<x;
        }

    }else if(sum==n-1){
        while(ans<=m/y){
            x++;
            ans+=x;
        }
        if(x>n){
            cout<<n;
        }else {
            cout<<x;
        }
    }else{

        for(int i=n;i>=1;i--){
            mx=max(f(i)+1,mx);
        }
        cout<<mx;

    }







    return 0;
}
