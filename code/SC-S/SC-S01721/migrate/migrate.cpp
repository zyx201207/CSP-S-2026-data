#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

//main
long long f[N],dp[N],dp2[N];
long long d;
int n;
//

//sgt
struct SGT
{
    int l,r;
    long long s;
}tr[4*N];
void build(int root,int l,int r)
{
    SGT *nw = &tr[root];
    nw->l = l,nw->r = r;
    nw->s = 0;
    if(l == r)  return ;
    int mid = l+r >> 1;
    build(root << 1,l,mid);
    build(root << 1 | 1,mid+1,r);
}
void updata(int root,int x,long long k)
{
    SGT *nw = &tr[root];
    if(nw->l == nw->r)
    {
        nw->s += k;
        return ;
    }
    int mid = nw->l + nw->r >> 1;
    if(x <= mid)    updata(root << 1,x,k);
    else    updata(root << 1 | 1,x,k);
    nw->s += k;
}
//

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1;i<=n;i++) cin >> f[i];
        if(c <= 10 || c > 12)
        {
            long long s = 0;
            for(int i = 1;i<=n;i++)
            {
                dp[i] = 0,dp2[i] = 1;
                int tj = i;
                build(1,0,n);
                updata(1,dp[i],dp2[i]);
                // cout << i <<":\n";
                for(int j = i+1;j<=n;j++)
                {
                    while(f[j]-f[tj] > d && tj <= j)    updata(1,dp[tj],-dp2[tj]),tj++;
                    int rt = 1;
                    while(tr[rt].l != tr[rt].r)
                    {
                        if(tr[rt << 1].s)   rt <<= 1;
                        else    rt <<= 1,rt |= 1;
                    }
                    dp[j] = tr[rt].l+1,dp2[j] = tr[rt].s;
                    if(dp2[j] == 2) s++;
                    else if(dp2[j] > 2) dp2[j] = 3;
                    updata(1,dp[j],dp2[j]);
                    // cout << dp[j] <<"," << dp2[j] <<"\n";
                }
            }
            cout << s <<"\n";
        }
        else if(c <= 12)    cout << (n == 1 ? 0:(d/(f[2]-f[1]) <= 1 ? 0:max(0ll,(n-2*(d/(f[2]-f[1]))+1)))) <<"\n";
    }
    return 0;
}