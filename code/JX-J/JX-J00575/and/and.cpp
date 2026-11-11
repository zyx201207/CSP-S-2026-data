#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N];
bool cmp(long long h,long long y){
    return h>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[1];
        return 0;
    }
    if(m==n){
        long long ans=a[1];
        for (int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    long long ans2=0;
    if(m==2){
        int yh;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                yh=a[i]&a[j];
                if(ans2<yh)ans2=yh;
            }
        }
        cout<<ans2;
        return 0;
    }
    return 0;
}