#include<bits/stdc++.h>
using namespace std;
#define TESTING
//#define HAND_PATH

void FREOPEN(const string& s){
    if(!freopen((s+".in").c_str(),"r",stdin)){
        cerr<<"Can not open file:"<<s<<".in\n";
        return;
    }
    if(!freopen((s+".out").c_str(),"w",stdout)){
        cerr<<"Can not open file:"<<s<<".out\n";
        return;
    }
}
namespace{
using ll=long long;
constexpr int N=500005;
ll v[N],m;
int n;
bool check(int k){
    ll sum=0;
    for(int i=1;i<k;i++){
        sum+=v[k]-v[i];
    }
    for(int i=k+1;i<=n;i++){
        if(sum<=m)return 1;
        sum-=v[i-1]-v[i-k];
        sum+=(v[i]-v[i-1])*(k-1);
    }
    return sum<=m;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    int l=1,r=n,ans=1;
    for(int mid=(l+r)/2;l<=r;mid=(l+r)/2){
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
}
/*
5 5
1 2 4 8 9
*/
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#if !defined(NON_JUDGE) || defined(TESTING)
    FREOPEN("crystal");
#elif defined(HAND_PATH)
    string path;
    cin>>path;
    FREOPEN(path);
#endif
    solve();
    return 0;
}
