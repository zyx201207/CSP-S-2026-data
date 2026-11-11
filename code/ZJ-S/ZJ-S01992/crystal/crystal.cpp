#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500050];
int ans=1;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int l=1,r=1,sum=a[l];l<=n&&r<=n;l++){
        while(r<n&&a[l]*(r-l+2)-sum-a[r+1]<=m) sum+=a[++r];
      //  cout<<l<<' '<<r<<'\n';
        ans=max(ans,r-l+1);
        sum-=a[l];
    }
    cout<<ans;
    return 0;
}
/*
思考T1
现在是14:39
由于我生病了，我给我预定时间在13:00内完成即可
开始思考思路
很容易就发现这本质是一个区间
一个for(int l,r)就行
9 8 4 2 1

实际完成时间15:00 
*/
