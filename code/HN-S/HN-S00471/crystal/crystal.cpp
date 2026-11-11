#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b) {
    return a>b;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(auto&x:a)cin>>x;
    sort(a.begin(),a.end(),cmp);
    int ans=0;

    // m次机会，n个数

    int l=0; // 左指针
    int r=0; // 右指针
    int fm=0; // 已经用掉了几次机会

    // 双指针
    /*
        右指针移动，r++
        将用掉机会加 fm+=a[l]-a[r]
        如果 fm>m {
            左指针移动，l++
            fm-=(a[l-1]-a[l])*(r-l+1);
        }
        统计答案：ans=max(ans,r-l+1);
    */

    while(l<n&&r<n) {//两个指针在数组里面
        fm+=a[l]-a[r];
        while(fm>m) {
            l++;
            fm-=(a[l-1]-a[l])*(r-l+1);
        }
        ans=max(ans,r-l+1);
        //cout<<l<<' '<<r<<'\n';
        r++;
    }
    cout<<ans;
}
