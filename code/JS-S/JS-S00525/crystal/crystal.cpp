#include<bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;
int n,m,ans=1;
int a[N],c[N],cn[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        c[i]=a[i]-a[i-1];
    }
    int i=1,j=1;
    int cnt=0;
    while(i<=j&&i<n&&j<n){
        while(m>=cn[j]&&j<n){
            j++;
            cn[j]=cn[j-1]+c[j]*(j-i);
            cnt++;
        }
        ans=max(ans,cnt);
        while(m<cn[j]&&i<=j){
            cn[j]-=(a[j]-a[i]);
            i++;
            cnt--;
        }
    }
    cout<<ans;
    return 0;
}
