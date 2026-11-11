#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=5e5+7;
int a[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++){
        int sum=0,num=1;
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]<=m-sum){
                sum+=a[i]-a[j];
                num++;
            }else{
                break;
            }
        }
        ans=max(ans,num);
    }
    cout << ans;
    return 0;
}
