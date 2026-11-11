#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define endl '\n'
const int inf=0x3f3f3f3f;
const double eps=1e-9;
using namespace std;

ll n,m,a[500005],sum[500005];int ans;

bool cmp(ll a,ll b){ return a>b; }

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<r){
            int mid=(l+r+1)/2;
            if(a[i]*(mid-i+1)-(sum[mid]-sum[i-1])<=m) l=mid;
            else r=mid-1;
        }
        ans=max(ans,l-i+1);
    }
    cout<<ans;
    //14:56

    return 0;
}
