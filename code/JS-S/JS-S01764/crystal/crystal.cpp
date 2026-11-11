#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m,cnt=0,diff[500005],res=0,pre[500005];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)   cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)   diff[i]=a[i]-a[i-1],pre[i]=pre[i-1]+diff[i];
    for(int l=1,r=1;r<=n;r++){
        int len=r-l+1;
        cnt+=diff[r]*(len-1);
        while(cnt>m){
            cnt-=pre[r]-pre[l];
            l++;
        }
        res=max(res,r-l+1);
    }
    cout << res;
    return 0;
}
