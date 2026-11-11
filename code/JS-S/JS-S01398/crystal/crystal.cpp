#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],c[N],s[N],ans;
bool check(int x){
    for(int i=2;i<=n-x+2;i++){
        int ji=(i-1)*(a[i+x-2]-a[i-1]);
        if((s[i+x-2]-s[i-1])-ji<=m) return 1;
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[i]=(a[i]-a[i-1])*i;
        s[i]=c[i]+s[i-1];
    }
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }

    }
    cout<<ans;
    return 0;
}
