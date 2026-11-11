#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],b[N],c[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    int l=1,r=1,cnt=0,ans=0;
    while(1){
        while(cnt<=m&&r<=n){
            r++;
            cnt+=(r-l)*b[r];
        }
        ans=max(r-l,ans);
        while(cnt>m&&l<=n){
            l++;
            cnt-=(a[r]-a[l]);
        }
        if(r>n||l>n) break;
    }
    cout<<ans;
    return 0;
}

