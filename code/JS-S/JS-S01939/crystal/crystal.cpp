#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int c[N];
signed main(void){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    stable_sort(a+1,a+n+1);
    int mid=a[n/2+1];
    for(int i=1;i<=n;++i) c[i]=abs(a[i]-mid);
    stable_sort(c+1,c+n+1);
    int cnt=0;
    for(int i=1;i<=n;++i){
        m-=c[i];
        if(m<0) break;
        else ++cnt;
    }
    cout<<cnt;
    return 0;
}
