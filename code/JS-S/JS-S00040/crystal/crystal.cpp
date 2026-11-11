#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[2000005],ab[2000005],mii=1000000000,mxx=-10000000000,rss;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mxx=max(mxx,a[i]);
        mii=min(mii,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=0;i<=2000000;i++){
        ab[i]=10000000000;
    }
    for(int cnt=mii;cnt<=mxx;cnt++){
        long long mi=100000000005,mid=0;
        for(int i=1;i<=n;i++){
            ab[i]=abs(a[i]-cnt);
            if(abs(a[i]-cnt)<mi){
                mi=abs(a[i]-cnt);
                mid=i;
            }
        }
        int l=mid,r=mid+1,ans=0,rs=0;
        while(l!=0||r!=n+1){
            if(ab[l]<=ab[r]){
                if(ans+ab[l]<=m){
                    ans+=ab[l];
                    rs++;
                    l--;
                }
                else{
                    break;
                }
            }
            else{
                if(ans+ab[r]<=m){
                    ans+=ab[r];
                    rs++;
                    r++;
                }
                else{
                    break;
                }
            }
        }
        rss=max(rss,rs);
    }
    cout<<rss;
    return 0;
}
