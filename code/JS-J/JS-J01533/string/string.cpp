#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define ldb long double
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define pdi pair<double,int>
#define pid pair<int,double>
#define fi first
#define se second
#define fp(x) fixed<<setprecision(x)
#define lb lower_bound
#define ub upper_bound
#define lowbit(x) (x)&(-x)
#define pb push_back
#define pf push_front
#define ep emplace
#define eb emplace_back
#define mpr make_pair
int T=1,n,a[200010],cnt=0;
char c[200010];
//O(n) n<=2e5 red/orange
void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        cin>>c[i];
    }
    //I don't think it's two pointers.
    int l=1,r=n;
    while(l<=r){
        if(a[l]>=a[r]){
            a[l]-=a[r];
            if(c[l]!=c[r]){
                cnt+=a[r];
            }
            r--;
        }else{
            //a[l]<a[r]
            a[r]-=a[l];
            if(c[l]!=c[r]){
                cnt+=a[l];
            }
            l++;
        }
    }
    cout<<cnt;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //cin>>T;
    while(T--){
        solve();
    }
}
