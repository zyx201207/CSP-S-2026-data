#include<bits/stdc++.h>
using namespace std;
#define int long long
#define llg long long
#define sig signed
#define usg unsigned
#define ull unsigned long long
int n,m;
int a[500005];
priority_queue<int,vector<int>,greater<int> >q;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;++i){
        int tmp=q.size();
        m-=tmp*(a[i]-a[i-1]);
        q.push(a[i]);
        while(m<0){
            m+=a[i]-q.top();
            q.pop();
        }
        if(q.size()>ans)ans=q.size();
    }
    cout<<ans;
    return 0;
}
