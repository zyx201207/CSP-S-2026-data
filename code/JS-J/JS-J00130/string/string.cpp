#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,total{};
char s[N];
ll a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        total+=a[i];
    }
    ll ans{};
    for(int i=1;i<=(n+1)/2;i++){
        if(s[i]!=s[n-i+1]){
            ans+=max(a[i],a[n-i+1]);
        }
        if(i==(n+1)/2&&abs(a[i]-1-max(a[i-1],a[n-i]))>0&&total%2==1){
            ans++;
        }
    }
    cout<<ans-(total%2);
    return 0;
}
