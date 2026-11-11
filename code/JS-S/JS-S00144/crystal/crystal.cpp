#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+5;
ll n,m,a[N];
ll sy,cnt,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n;i>=2;i--){
        if(a[i]==a[i+1])continue;
        sy=m;
        cnt=0;
        for(int j=i;j>=1;j--){
            if(sy>=a[i]-a[j]){
                sy-=a[i]-a[j];
                cnt++;
            }
            else break;
        }
        ans=max(cnt,ans);
    }
    cout<<ans;
    return 0;
}
