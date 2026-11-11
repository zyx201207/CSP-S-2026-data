#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2*1e5+5;
ll n,m,ma,cnt,h,a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[++cnt];
    }
    for(int i=1;i<=cnt;i++){
        h=a[i];
        for(int j=1;j<=m;j++){
            h=h&a[i+1];
        }
        ma=max(ma,h);
    }
    cout<<ma;
}
