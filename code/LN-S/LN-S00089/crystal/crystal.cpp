#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500006];
int pre[500006];
int ans=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=i,r=n,mid=0;
        while(l<=r){
            mid=(l+r)/2;
            if(m>=a[mid]*(mid-i+1)-pre[mid]+pre[i-1]){
                ans=max(ans,mid-i+1);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }
    cout<<ans;
    return 0;
}
