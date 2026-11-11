#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500000+11;
ll a[maxn];
ll m;

bool check(int idx){  //O(n)
    ull sum=0;
    //
    for(int i=1;i<=idx;i++){
        if(a[i]==a[idx]) break;
        //
        sum+=a[idx]-a[i];
        if(sum>m) return 0;
    }
    //
    return 1;
}

int solve(int l,int r){  // O(log n)
    ll ans;
    //
    while(l<r){
        int mid=(l+r)/2;
        //
        if(check(mid)){
            //for(;a[mid+1]==a[mid] && mid<=r;mid++);
            //
            ans=mid;
            l=mid+1;
        }else{
            r=mid;
        }
    }
    //
    return ans;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //
    int n;
    cin >> n >> m;
    //
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    //
    sort(a+1,a+n+1);
    //
    int ans=solve(1,n);
    //
    cout << ans;
    //
    //fclose(stdin);
    //fclose(stdout);
    //
    return 0;
}
/*
5 2
1 1 2 2 3

*/
