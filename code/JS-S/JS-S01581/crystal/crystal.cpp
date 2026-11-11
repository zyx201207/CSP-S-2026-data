#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
int sum[N];
int ans=0;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0),cout.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        int l=0,r=i;
        while(l<=r){
            int mid=(l+r)/2;
            int num=a[i]*(i-mid)-(sum[i]-sum[mid]);
            if(num>m){
                l=mid+1;
            }else{
                ans=max(ans,i-mid);
                r=mid-1;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9
*/
