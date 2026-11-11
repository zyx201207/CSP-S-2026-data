#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,a[N],l,r,i,j,tot,lrmax,ans;
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        tot+=a[i];
    }
    i=0;
    j=n+1;
    while(1){
        if(l+a[i+1]>tot/2&&r+a[j-1]>tot/2) break;
        if(l+a[i+1]<r+a[j-1]){
            if(l+a[i+1]>=r){
                ans+=min(l+a[i+1]-r,a[i+1])*(c[i+1]!=c[j-1]);
            }
            l+=a[++i];
        }else{
            if(r+a[j-1]>=l){
                ans+=min(r+a[j-1]-l,a[j-1])*(c[i+1]!=c[j-1]);
            }
            r+=a[--j];
        }
    }
    cout<<ans;
    return 0;
}
