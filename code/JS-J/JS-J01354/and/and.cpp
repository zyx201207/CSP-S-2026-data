#include<bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+r>>1)
using namespace std;
const int N=200005;
int a[N];
int n,m;
int b[N];

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=31;i>=0;i--){
        int t=0;
        for(int j=1;j<=n;j++){
            if(a[j]>>i&1) b[++t]=a[j];
        }
        if(t>=m){
            for(int j=1;j<=t;j++) a[j]=b[j];
            n=t;
        }
    }
    int ans=a[1];
    for(int i=2;i<=m;i++) ans=ans&a[i];
    cout<<ans;
    return 0;
}