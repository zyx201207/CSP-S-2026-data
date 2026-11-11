#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],sum[N];
bool check(int x,int i){
    if((i-x+1)*a[i]-(sum[i]-sum[x-1])<=m) return 1;
    return 0;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
        // if(a[i]*i-sum>m){cout<<i-1;return 0;}
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid,i)) ans=max(ans,i-mid+1),r=mid-1;
            else l=mid+1; 
        }
    }
    cout<<ans;
    return 0;
    //这是不对的。可能并不需要选择前面的水晶。只需要选择后面就可以了。
    //如何进行打掉前面的操作？
    //我们依旧枚举最终目标。可以通过二分查找最左的满足条件的数字。
}