#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
int n,m,a[N],s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            int len=i-mid+1;
            if(a[i]*len-(s[i]-s[mid-1])>m) l=mid+1;
            else r=mid;
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans<<"\n";
    return 0;
}