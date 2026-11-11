#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=500010;
LL arr[N],n,m,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(LL i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    for(LL i=0,j=0,res=0;j<n;j++){
        res+=(arr[j]-arr[j-1])*(j-i);
        while(res>m){
            res-=arr[j]-arr[i++];
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;
}
