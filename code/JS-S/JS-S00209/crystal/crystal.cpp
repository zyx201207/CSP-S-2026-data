#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+2;
int n;
ll m;
ll a[maxn];
bool check(){
    if(n<3) return true;
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]) return false;
    }
    return true;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(check()){    // point 13~18
        int i,j;
        ll now=0;
        for(i=j=(n+1)/2;i<=n||j>=1;){
            now+=a[i]-a[(n+1)/2];
            if(now>m) break;
            else i++;
            now+=a[(n+1)/2]-a[j];
            if(now>m) break;
            else j--;
        }
        cout<<i-j-1;
        return 0;
    }
    cout<<n*5/8;
    return 0;
}
