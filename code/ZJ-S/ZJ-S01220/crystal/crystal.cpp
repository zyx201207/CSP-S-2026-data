#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
const int num=500100;
int a[num], n, m, suf[num],mx;

int cntl(int x,int i){
    return suf[x] - suf[i]-(a[n] - a[i]) * (i - x);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    F(i, 1, n)
        cin >> a[i];
    sort(a + 1, a + n + 1);
  
    for (int i = n; i >= 1;i--){
        suf[i] = suf[i + 1] + (a[n]-a[i]);
    }
    
    F(i,1,n){
        int l = 1, r = i,ans;
        while(l<=r){
            int mid=(l+r)>>1;
            if(cntl(mid,i)<=m){
                ans=mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
       
        
        mx = max(mx, i-ans + 1);
       
    }
    cout << mx << endl;
}