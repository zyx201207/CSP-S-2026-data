#include <bits/stdc++.h>
using namespace std;
int n,ans;
int m;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int tmp=m,j=1,cnt;
        if(a[i]-tmp>0) j=lower_bound(a+1,a+1+i,a[i]-tmp)-a-1;
        for(;j<=i;j++){
            cnt=0;
            for(int k=j;k<=i;k++){
                if(tmp>=(a[i]-a[k])){
                    tmp-=(a[i]-a[k]);
                    cnt++;
                }
            }
            ans=max(ans,cnt);
            if(cnt==i-j+1) break;
        }
    }
    cout<<ans;
    return 0;
}
