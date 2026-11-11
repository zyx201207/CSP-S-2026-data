#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
int n;
ll m;
ll a[MAXN];
ll pre[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;++i){
        pre[i]=pre[i-1]+a[i];
    }
    int ans=0;
    int l=1;
    for (int r=1;r<=n;++r){
        while(a[r]*(r-l+1)-(pre[r]-pre[l-1])>m){
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
