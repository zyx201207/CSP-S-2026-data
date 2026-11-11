#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],s[N];
bool chk(int x){
    for(int l=1;l+x-1<=n;l++){
        int r=l+x-1;
        if(a[r]*x-(s[r]-s[l-1])<=m)  return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)  s[i]=s[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=l+r>>1;
        if(chk(mid)){
            ans=mid;
            l=mid+1;
        }
        else  r=mid-1;
    }
    cout<<ans;
    return 0;
}
