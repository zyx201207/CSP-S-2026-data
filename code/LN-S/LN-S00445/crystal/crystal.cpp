#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500005],s[500005];
bool check(int pos,int mid){
    return a[pos]*(pos-mid)-(s[pos-1]-s[mid-1])<=m;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            continue;
        }
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(i,mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans;
    return 0;
}
