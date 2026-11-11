#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,arr[500010],ans;
ll sum[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int flag=-1;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==i&&flag!=0){
            flag=1;
        }
        else{
            flag=0;
        }
    }
    if(flag==1){
        sum[0]=0;
        for(ll i=1;i<n;i++){
            sum[i]=sum[i-1]+i;
            if(arr[i]<=m){
                sum++;
            }
            else{
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    ll cnt=arr[1]-arr[0];
    for(ll i=1;i<n;i++){
        if(arr[i]-arr[i-1]==cnt){
            cnt=arr[i]-arr[i-1];
        }
        else{
            cnt=-1;
            break;
        }
    }
    if(cnt!=-1){
        sum[0]=0;
        for(ll i=1;i<n;i++){
            sum[i]=sum[i-1]+cnt;
            if(sum[i]<=m){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
