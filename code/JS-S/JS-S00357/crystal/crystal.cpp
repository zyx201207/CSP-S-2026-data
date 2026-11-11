#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],s[N];
ll n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            int av=(s[j]+m)/(j-i+1);
            if(a[j]>av) continue;
            else {
                ans=max(ans,j-i+1);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
