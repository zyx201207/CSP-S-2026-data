#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
const int MAXN(500005);
int n,m;
int a[MAXN],num[MAXN];
map<int,int> cnt;
signed main(){
    IOS;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    sort(a+1,a+1+n);
    int l=1,r=cnt[a[1]],sum(0),ans(0);
    while(1){
        while(sum<=m&&r<=n){
            ans=max(ans,r-l+1);
            int tr=r+cnt[a[r+1]];
            if(r<n) sum+=(a[tr]-a[r])*(r-l+1);
            else break;
            r=tr;
        }
        sum-=a[r]-a[l++];
        if(r>=n)break;
    }
    cout<<ans;
    return 0;
}
