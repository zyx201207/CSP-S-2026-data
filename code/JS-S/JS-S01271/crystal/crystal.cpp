#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int n,m,a[N],b[N],lans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    lans=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            int ll=mid;
            int len=i-ll+1;
            int val=len*a[i]-(b[i]-b[ll-1]);
            if(val<=m){
                ans=ll;
                r=mid-1;
            }else l=mid+1;
        }
        if(ans!=-1)lans=max(lans,i-ans+1);
    }
    cout<<lans;
    return 0;
}
//14:36 true answer && start
//14:43 start testing
//14:49 no!!!!
//14:50 small problem
//14:51 over
