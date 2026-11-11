#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ma=LONG_MIN;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    sort(a+1,a+n+1);
    int ans=1;
    for(int i=2;i<=ma;i++){
        long long cnt=0;
        int num=0;
        for(int j=n;j>=1;j--){
            if(a[j]>i) continue;
            cnt+=i-a[j];
            if(cnt<=m){
                num++;
            }else{
                break;
            }
        }
        ans=max(ans,num);
    }
    cout<<ans;
    return 0;
}
