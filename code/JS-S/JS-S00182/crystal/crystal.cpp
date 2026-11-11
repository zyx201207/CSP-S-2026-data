#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;ll m;
ll a[N];
ll sum[N];
int ans=0;
bool check(int cnt,int i){
    return (cnt-1)*a[i]-(sum[i-1]-sum[i-cnt])<=m;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=((l+r)>>1)+1;
            if(check(mid,i)) l=mid;
            else r=mid-1;
        }
        ans=max(ans,l);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
5 10
10 3 6 -7 20
*/
