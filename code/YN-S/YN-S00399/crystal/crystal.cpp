#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;
ll n,m,a[N],cost[N];

bool check(int len){
    bool flag=1;
    for(int l=1;l+len-1<=n;l++){
        int r=l+len-1;
        ll v=cost[r]-cost[l]-(l-1)*(a[r]-a[l]);
        if(v<=m){
            flag=0;
            return 1;
        }
    }
    return 0;
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        cost[i]=cost[i-1]+1LL*(i-1)*(a[i]-a[i-1]);
    }
    int lo=1,hi=n;
    while(lo<hi){
        int mid=lo+((hi-lo+1)>>1);
        if(check(mid)){
            lo=mid;
        }
        else{
            hi=mid-1;
        }
    }
    cout<<lo<<"\n";
    return 0;
}
