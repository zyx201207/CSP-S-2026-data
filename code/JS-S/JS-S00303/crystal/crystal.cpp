#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define m_p make_pair
#define P pair<int,int>
#define lowbit(x) (x&(-x))
#define fr first
#define sc second
typedef long long ll;
ll a[500005],S[500005];
ll n,m;
bool check(ll l,ll r){
    return (a[r]*(r-l+1)-(S[r+1]-S[l]))<=m;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) S[i+1]=S[i]+a[i];
    int j=0,ans=1;
    for(int i=0;i<n;i++){
        while(j<n&&check(i,j)) j++;
        //cout<<i<<" "<<j<<" "<<ans<<endl;
        ans=max(ans,j-i);
    }
    cout<<ans<<endl;
    return 0;
}