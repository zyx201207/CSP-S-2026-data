#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,num[N],a[N];
signed main()
{
//#ifndef ZHOUYUDEBUG666
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
//#endif
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int l=1,r=n,mid=0,ans=0,ans2=0;
        while(l<=r){
            mid=(l+r)/2;
            if(a[mid]>=i){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(a[ans]!=i){cout<<0<<' ';continue;}
        l=0;r=n;mid=0;
        while(l<=r){
            mid=(l+r)/2;
            if(a[mid]<=i){
                ans2=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<ans2<<' ';
    }
    return 0;
}


