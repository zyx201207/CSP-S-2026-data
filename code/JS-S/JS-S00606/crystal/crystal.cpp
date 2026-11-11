#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
ll n,m,a[500005],now=0,ans=0;
queue <ll> q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    ll need=0;
    for (int i=1;i<=n;i++){
        need+=now*(a[i]-a[i-1]);
        q.push(i);
        now++;
        while (!q.empty() && need>m){
            need-=a[i]-a[q.front()];
            now--;
            q.pop();
        }
        ans=max(ans,now);
    }
    printf("%lld",ans);
    return 0;
}
