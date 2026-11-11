#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define dep(i,e,s) for(int i=e;i>=s;i--)
#define lc id<<1
#define rc id<<1|1
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int maxn=5e5+10;
int n;
ll a[maxn],m,ans=1,cnt=0;
deque<int> q;
signed main(){
    freopen("crystal.in","r",stdin);    
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1;
    rep(i,2,n){
        cnt+=(a[i]-a[i-1])*(i-l);
        while(cnt>m) cnt-=a[i]-a[l],l++;
        ans=max(ans,(ll)(i-l+1));
    }
    cout<<ans<<"\n";
    return 0;
}
/*
5 5
1 2 4 8 9
*/