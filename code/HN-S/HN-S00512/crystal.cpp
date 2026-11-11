#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum[1000005],a[1000005];
int n,m;
deque<int> q;
bool check(int Len){
    q.clear();
    for(int i=1;i<=Len;i++){
        while(q.size() && a[q.back()]<=a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(int l=1,r=Len;r<=n;l++,r++){
        while(q.size() && q.front()<l){
            q.pop_front();
        }
        int W=a[q.front()];
        if(W*Len-(sum[r]-sum[l-1])<=m){
            return 1;
        }
        if(r+1<=n){
            while(q.size() && a[q.back()]<=a[r+1]){
                q.pop_back();
            }
            q.push_back(r+1);
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}