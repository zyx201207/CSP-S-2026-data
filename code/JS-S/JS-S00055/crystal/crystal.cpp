#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=1e12;
ll n,m,a[N];
ll ans;
ll b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        if(a[i]==a[i+1])continue;
        ll sum;
        for(int j=i;j>=1;j--){
            if((b[i]-b[j-1]+m)/(i-j+1)>=a[i]){
                sum=i-j+1;
            }
            else{
                break;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
