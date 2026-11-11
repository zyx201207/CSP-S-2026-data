#include <bits/stdc++.h>
#define lint __int128
#define int long long
#define Il inline
#define fi first
#define se second
#define vec vector
#define pb push_back
#define IT ::iterator
#define p_q priority_queue

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef double db;
const int N=5e5;
const db eps=1e-9;

// bool P1;

int n,m,a[N+5],s[N+5];

Il int solve(int p){
    int l=1,r=p;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[p]*(p-mid+1)-(s[p]-s[mid-1])<=m){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return p-(r+1)+1;
}

// bool P2;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cout<<abs((&P1)-(&P2))/1024/1024;return 0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=max(ans,solve(i));
    }
    cout<<ans;
    return 0;
}