#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
int n,m,a[500005],ans,j=1,cnt;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    a[0]=a[1];
    int qsy=m;
    for(int i=1;i<=n;i++){
        m+=(a[j]-a[i-1]);
        if(j<i) j=i,m=qsy;
        cnt=j-i+1;
        while(j<n&&m>=(a[j+1]-a[j])*cnt){
            m-=(a[j+1]-a[j])*cnt,j++;
            cnt++;
        }
        ans=max(ans,cnt);
        if(j==n) break;
    }
    cout<<ans<<'\n';
    return 0;
}
//wo qu
//wo hao xiang A le t1
//15:29 (tiao le ban tian fa xian sort fang cuo wei zhi le
//xie xie CCF
//xie xie shuang zhi zhen
//qsy I love you!
