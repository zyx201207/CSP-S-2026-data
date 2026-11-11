#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,lm;
int a[500005];
bool check(int x){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x){
            sum+=x-a[i];
            if(sum>m)return false;
        }
        else break;
    }
    if(sum<=m)return true;
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n>> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    int l=a[1],r=a[n],mid=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    int ans=l-1,ans1=l;
    int cnt=0,cnt1=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=ans)cnt++;
        else break;
    }
    for(int i=n;i>=1;i--){
        if(a[i]<=ans1)cnt1++,m=m-ans+a[i];
        if(m<0){
            cnt1--;
            break;
        }
    }
    //cout << cnt1 << " " <<cnt << endl;
    cout << max(cnt1,cnt);
    return 0;
}
