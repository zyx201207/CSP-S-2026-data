#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

ll n,a[500005],m,c[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        c[i-1] = a[i]-a[i-1];
    }

    if(c[1]>m){
        cout<<1;
        return 0;
    }
    ll cnt=1;
    ull s=0;
    for(int i=1;i<n;i++){
        if(s+c[i]>m){
            cout<<cnt;
            return 0;
        }
        cnt++;
        s += c[i];
    }

    cout<<cnt;

    return 0;
}
/*/
I LOVE CCF!!!🤓👆
/*/
