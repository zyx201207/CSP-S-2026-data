#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int qzh[500010];
int ans=0;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        qzh[i] = qzh[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int l = 1,r = i;
        while(l<r)
        {
            int mid = (l+r) >> 1;
            if(a[i]*(i-mid+1ll)-(qzh[i]-qzh[mid-1])<=m) r = mid;
            else l = mid+1; 
        }
        ans = max(ans,i-l+1);
    }
    cout << ans << endl;
    return 0;
}