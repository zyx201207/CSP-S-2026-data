#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 6;
int n,m;
int a[N],pre[N];
bool check(int now,int len){
    int sum = pre[now-1] - pre[now-len-1];
    sum = a[now] * len - sum;
    if(m>=sum) return 1;
    else return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int ans = -1;
    for(int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i];
    for(int i=1;i<=n;i++){
        int l=0,r=i-1;
        while(l<r){
            int mid = (l+r+1)/2;
            if(check(i,mid)){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        ans = max(ans,l);
    }
    cout << ans + 1;
    return 0;
}
