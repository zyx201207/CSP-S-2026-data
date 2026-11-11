#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,a[N],ans,cnt;
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    ll c,d;
    c=1;
    d=n;
    while(c<=d){
        ll ww=max(a[c],a[d]);
        if(a[c]==ww&&a[d]==ww){
            if(b[c]!=b[d]){
                ans+=ww;
            }
            c++;
            d--;
        }
        else if(a[c]==ww){
            cnt=a[c]-a[d];
            if(b[c]!=b[d]){
                ans+=a[d];
            }
            a[c]-=cnt;
            d--;
        }
        else if(a[d]==ww){
            cnt=a[d]-a[c];
            if(b[c]!=b[d]){
                ans+=a[c];
            }
            a[d]-=cnt;
            c++;
        }
    }
    cout<<ans;
    return 0;
}
