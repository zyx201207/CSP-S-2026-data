#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long check(int x){
    priority_queue<long long,vector<long long>,greater<long long> > pq;
    for(int i=1;i<=n;i++){
        if(x >= a[i])pq.push(x - a[i]);
    }
    long long ans = 0,m1=m;
    while(!pq.empty()){
        if(m1 >= pq.top()){
            m1 -= pq.top();
            ans ++;
        }
        pq.pop();
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    if(n == 1){
        cout << 1;
        return 0;
    }
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    long long l=1,r=n,ans=0;
    //cout << check(4) << '\n';
    while(l < r){
        long long mid1 = l + (r - l) / 3,mid2 = l + (r - l) / 3 * 2;
        long long ans1 = check(a[mid1]);
        long long ans2 = check(a[mid2]);
        //cout << l << ' ' << r << '\n';
        if(ans1 >= ans2){
            ans = max(ans1,ans);
            r = mid2 - 1;
        }
        else{
            ans = max(ans2,ans);
            l = mid1 + 1;
        }
    }
    cout << ans;
}