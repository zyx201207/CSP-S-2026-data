#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200005;
ll n;
ll a[N];
char s[N];
ll ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    ll l=1,r=n;
    while(l<r){
        if(a[l]<=a[r]){
            a[r]-=a[l];
            if(s[l]!=s[r]){
                ans+=a[l++];
            }
            else l++;
        }
        else if(a[l]>a[r]){
            a[l]-=a[r];
            if(s[l]!=s[r]){
                ans+=a[r--];
            }
            else r--;
        }
    }
    cout<<ans;
    return 0;
}
