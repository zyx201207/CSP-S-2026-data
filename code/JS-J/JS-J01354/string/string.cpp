#include<bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+r>>1)
using namespace std;
const int N=200005;
int n;
int a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    // cout<<n<<'\n';
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n;
    int ans=0;
    while(l<r){
        // cout<<l<<' '<<r<<' '<<c[l]<<' '<<c[r]<<'\n';
        if(c[l]==c[r]){
            if(a[l]==a[r]){
                l++;
                r--;
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }else if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
        }else{
            // cout<<1<<'\n';
            if(a[l]==a[r]){
                ans+=a[l];
                l++;
                r--;
            }else if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }else if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}