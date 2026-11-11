#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,ans;
ll a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    for(int i=1;i<=n;i++){
        if((i-1)*a[i]-s[i-1]<=m){
            ans=i;
        }
        else{
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
