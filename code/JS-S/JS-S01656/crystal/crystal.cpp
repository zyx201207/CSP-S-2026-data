#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=5e5+10;

int n,m;
ll a[N],s[N];

inline bool check(int x){
    for(int i=1;i<=n-x+1;i++){
        int j=i+x-1;
        if(s[j]-s[i-1]+m>=a[j]*x) return 1;
    }
    return 0;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=0,r=n+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
    return 0;
}
