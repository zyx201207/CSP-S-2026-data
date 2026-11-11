#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N=5e5+10;
int n;
int m;
int a[N];
int s[N];
int ans;

int find(int x){
    int l=1,r=x+1;
    while(l < r){
        int mid=(l+r)>>1;
        if((a[x]*(x-mid+1)-s[x]+s[mid-1]) > m){
            l=mid+1;
        }else {
            r=mid;
        }
    }
    return l-1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in" ,"r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1; i<=n; ++i){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1; i<=n; ++i){
        ans=max(ans,i-find(i));
    }
    cout<<ans<<'\n';
    return 0;
}
