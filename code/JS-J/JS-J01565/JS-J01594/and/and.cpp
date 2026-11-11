#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define lowbit(x) x&(-x)
const int N=1e6+10;
int n,k,tot;
int a[N],sum[N];
bool cmp(int x,int y) {
    return x>y;
}
signed main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        int sum=1;
        bool flag=0;
        for(int j=1;j<=30;j++) {
            sum*=2;
            if(x==sum) {
                flag=1;
                break;
            }
        }
        if(flag) continue;
        else a[++tot]=x;
    }
    sort(a+1,a+1+tot,cmp);
    int ans=a[1];
    for(int i=2;i<=k;i++) {
        ans=ans&a[i];
    }
    cout<<ans<<'\n';
    return 0;
}