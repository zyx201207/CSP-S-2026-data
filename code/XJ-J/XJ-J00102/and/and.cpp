#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=200005;
int arr[MAXN];
bitset<MAXN> bs;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    int res=0;
    bs.set();
    for(int k=31;k>=0;k--){
        int cnt=0;
        for(int i=0;i<n;i++) if((arr[i]>>k&1)&&bs[i]) ++cnt;
        if(cnt>=m){
            res|=(1<<k);
            for(int i=0;i<n;i++) if(!(arr[i]>>k&1)) bs[i]=0;
        }
    }
    cout<<res<<'\n';
    return 0;
}