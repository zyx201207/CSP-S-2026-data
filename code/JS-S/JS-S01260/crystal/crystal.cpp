#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+n+1);
    long long ans=1;
    long long l=1,r=2;
    long long cnt=0;
    while(r<=n){
        cnt+=(arr[r]-arr[r-1])*(r-l);
        while(cnt>m&&l<r){
            cnt-=arr[r]-arr[l];
            l++;
        }
        ans=max(ans,r-l+1);
        r++;
    }
    cout << ans;
    return 0;
}
