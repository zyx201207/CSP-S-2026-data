#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
const int num=500100;
int a[num], n, m, R[num],suf[num],pre[num],mx;
int cntr(int x,int i){
    return pre[x] - pre[i]-(a[i] - a[1]) * (x - i);
}
int cntl(int x,int i){
    return suf[x] - suf[i]-(a[n] - a[i]) * (i - x);
}
pii ckl(int x,int i){
    int sum = cntr(x, i);
    if(sum>m)return pii(0,0);
    int res = m - sum;
    int l = 1, r = i,ans=i;
    while(l<=r){
        int mid = (l + r) >> 1;
        if(a[i]-a[mid]<=a[x]-a[i])
            r=mid-1, ans = mid;
        else
            l=mid+1;
    }
    int s = cntl(ans, i);
    if(s>res)
        return pii(0, 0);
    else
        return pii(1, ans);
}
pii ckr(int x,int i){
    int sum = cntl(x, i);
    if(sum>m)
        return pii(0, 0);
    int res=m-sum;
    int l = i, r = n, ans = i;
    while(l<=r){
        int mid = (l + r) >> 1;
        if(a[mid]-a[i]<=a[i]-a[x])
            l=mid+1,ans=mid;
        else
            r = mid - 1;
    }
    int s = cntr(ans, i);
    if(s>res)
        return pii(0, 0);
    else
        return pii(1, ans);
}
signed main(){
    // freopen("crystal.in","r",stdin);
    // freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    F(i, 1, n)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    F(i, 1, n){
            pre[i] = pre[i - 1] + (a[i] - a[1]);
    }
    for (int i = n; i >= 1;i--){
        suf[i] = suf[i + 1] + (a[n]-a[i]);
    }
    // cerr << suf[1] << endl;
    F(i,1,n){
        int l = ((i == 1) ? 1 : (max(i, R[i - 1]))), r = n,ansl=i,ansr=i;
        while(l<=r){
            int mid=(l+r)>>1;
            pii c = ckl(mid,i);
            if(c.fi){
                ansl=c.se;ansr=mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        l = 1, r = ansl-1;
        while(l<=r){
            int mid = (l + r) >> 1;
            pii c = ckr(mid, i);
            if(c.fi){
                if(c.se-mid>ansr-ansl){
                    ansl = mid, ansr = c.se;
                }
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
      
        cerr << ansl << ' ' << i << ' ' << ansr << endl;
        cerr << cntl(ansl, i) << ' ' << cntr(ansr, i) << endl;
        
        mx = max(mx, ansr - ansl + 1);
        R[i] = ansr;
    }
    cout << mx << endl;
}