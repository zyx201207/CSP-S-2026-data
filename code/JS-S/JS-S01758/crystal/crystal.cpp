#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n=0;
ll m=0;
vector<ll>a;
int ans=0;
ll cur=0;

inline bool chmax(int& a,const int b){return a<b?1,a=b:0;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    cur=m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a.begin()+1,a.end());
    for(int l=1,r=1;r<=n;++r){
        cur-=1ll*(r-l)*(a[r]-a[r-1]);
        if(cur>=0){chmax(ans,r-l+1); continue;}
        while(cur<0){
            cur+=(a[r]-a[l])*1ll;
            ++l;
        }
        chmax(ans,r-l+1);
    }
    cout<<ans<<'\n';
}