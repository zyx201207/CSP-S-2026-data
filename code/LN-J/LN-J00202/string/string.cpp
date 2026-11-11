#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ri register int
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
ll ans;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ri i=1;i<=n;++i)cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l]==a[r]){
            ++l;
            --r;
        }
        else if(a[l]>a[r]){
            a[l]-=a[r];
            --r;
        }
        else {
            a[r]-=a[l];
            ++l;
        }
    }
    cout<<ans;
    return 0;
}
