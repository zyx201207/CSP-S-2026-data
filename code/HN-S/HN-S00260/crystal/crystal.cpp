#include<bits/stdc++.h>
#define int long long
#define f(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
int n,m,a[500005];
queue<int>q;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0); 
    cin>>n>>m;
    f(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0,s=0;
    f(i,1,n){
        s+=q.size()*(a[i]-a[i-1]);
        while(!q.empty()&&s>m){
            s-=a[i]-a[q.front()];
            q.pop();
        }
        q.push(i);
        ans=max(ans,(int)q.size());
    }
    cout<<ans;
    return 0;
}
