#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5;
int a[N+10];
int sum[N+10];
int n,m;
deque<int> q;
bool check(int x){
    while(!q.empty()) q.pop_front();
    for(int i=1;i<=n;i++){
        while(!q.empty()&&a[q.back()]<a[i]) q.pop_back();
        q.push_back(i);
        if(i>=x){
            while(!q.empty()&&q.front()<i-x+1) q.pop_front();
            if(a[q.front()]*x-sum[i]+sum[i-x]<=m) return true;
        }
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    cout<<'\n';
    int lft=1,rgt=n,mid;
    while(lft<=rgt){
        mid=(lft+rgt)>>1;
        if(check(mid)) lft=mid+1;
        else rgt=mid-1;
    }
    cout<<rgt<<'\n';
    return 0;
}