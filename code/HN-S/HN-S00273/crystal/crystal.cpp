#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fi first
#define sc second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pb push_back
#define umap unordered_map
#define pq priority_queue
#define mset multiset
#define ull unsigned long long
#define i128 __int128
#define fixs fixed<<setprecision
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x)
const int maxn=5e5+10;
int n,res;
ll m,a[maxn],s[maxn];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,mid=0,pos=i;
        while(l<=r) mid=(l+r)>>1,(s[i]-s[mid-1]+m>=a[i]*(i-mid+1)?pos=mid,r=mid-1:l=mid+1);
        res=max(res,i-pos+1);
    }
    cout<<res<<endl;
}
int main(){
    FileIO("crystal");
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}