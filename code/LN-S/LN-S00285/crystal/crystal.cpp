#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n;
ll m,a[N],preS[N],t[N];
ll getneed(int l,int r){
    return (r-l+1)*a[r]-(preS[r]-preS[l-1]);
}
int bs(int st){
    int l=st,r=n;
    int res=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(getneed(st,mid)<=m){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return r-st+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        preS[i]=preS[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,bs(i));
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
