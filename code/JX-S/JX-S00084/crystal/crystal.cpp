#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
const int N = 5e5+5;
int a[N],sum[N],s[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        s[i]=a[i]*(i-1)-sum[i-1];
    }
    for(int i=n;i>=1;i--){
        if(m>=s[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
