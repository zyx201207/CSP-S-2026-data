#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
const int N=5e5+10;
long long a[N];
queue<long long>q;
long long cur=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    q.push(a[1]);
    for(int i=2;i<=n;i++){
        cur+=(a[i]-a[i-1])*q.size();
        q.push(a[i]);
        while(cur>m&&q.size()){
            cur-=a[i]-q.front();
            q.pop();
        }
        ans=max(ans,(long long)q.size());
    }
    cout<<ans<<endl;
    return 0;
}
