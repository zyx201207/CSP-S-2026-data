#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
ll n;
ll a[N]={0};
ll b[N]={0};
ll x=0;
ll pos;
ll m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=(__builtin_popcount(a[i]));
    }
    sort(b+1,b+n+1);
    for(int i=n;i>=n-m+1;i--){
        ll tmp=(__builtin_popcount(a[i]));
        if(i==n&&tmp==b[i]){
            pos=a[i];
            continue;
        }
        if(tmp==b[i]){
            pos=(pos&a[i]);
        }
    }
    cout<<pos<<endl;
    return 0;
}
