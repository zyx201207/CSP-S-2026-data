#include <bits/stdc++.h>
using namespace std;
constexpr int N=5e5+25;
int n;
long long m,a[N],ans=1,res,b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
    int l=1,r=1;
    long long re=0,cnt;
    for(l=1;l<=n;l++){
        while(r<n&&m>=b[r+1]*ans){
            r++;
            re=b[r]*ans;
            m-=re;
            ans++;
        }
        cnt=r-l+1;
        res=max(res,cnt);
        ans--;
        m+=(a[r]-a[l]);
    }
    cout<<res;
    return 0;
}
