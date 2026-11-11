#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct st{
    int x;
    char ch;
} a[N];
signed main(void){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].x>>a[i].ch;
    int sum=0;
    for(int l=1,r=n;l<r;++l,--r){
        int minv=min(a[l].x,a[r].x);
        if(a[l].ch!=a[r].ch) sum+=minv;
        a[l].x-=minv;
        a[r].x-=minv;
        if(!a[l].x){
            ++r;
            continue;
        }
        if(!a[r].x){
            --l;
            continue;
        }
    }
    cout<<sum;
    return 0;
}
